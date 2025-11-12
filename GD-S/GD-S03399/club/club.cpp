#include<bits/stdc++.h>
using namespace std;
struct st{
	int li[4],sx[4];
};
st a[1000000];
int ji[4];
int club[4][1000000];
void cl(st &a){
	if(a.li[1]>a.li[2]){
		if(a.li[1]>a.li[3]){
			a.sx[1]=1;
			if(a.li[2]>a.li[3]){
				a.sx[2]=2;
				a.sx[3]=3;
			}
			else{
				a.sx[2]=3;
				a.sx[3]=2;
			}
		}
		else{
			a.sx[1]=3;
			a.sx[2]=1;
			a.sx[3]=2;
		}
	}
	else{
		if(a.li[1]>a.li[3]){
			a.sx[1]=2;
			a.sx[2]=1;
			a.sx[3]=3;
		}
		else{
			a.sx[3]=1;
			if(a.li[2]>a.li[3]){
				a.sx[1]=2;
				a.sx[2]=3;
			}
			else{
				a.sx[1]=3;
				a.sx[2]=2;
			}
		}
	}
	return;
}
int js(int i){
	return a[i].li[a[i].sx[1]]-a[i].li[a[i].sx[2]];
}
bool cmp2(int st1,int st2){
	return js(st1)<js(st2);
}

void solve(){
	ji[0]=ji[1]=ji[2]=ji[3]=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].li[1]>>a[i].li[2]>>a[i].li[3];
		cl(a[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		club[a[i].sx[1]][++ji[a[i].sx[1]]]=i;
		ans+=a[i].li[a[i].sx[1]];
	}
	if(ji[1]>n/2){
		sort(club[1]+1,club[1]+ji[1]+1,cmp2);
		int i=1;
		while(ji[1]>n/2){
			int st1=club[1][i];
			ans-=a[st1].li[a[st1].sx[1]]-a[st1].li[a[st1].sx[2]];
			ji[1]--;
			i++;
		}
	}
	else if(ji[2]>n/2){
		sort(club[2]+1,club[2]+ji[2]+1,cmp2);
		int i=1;
		while(ji[2]>n/2){
			int st1=club[2][i];
			ans-=a[st1].li[a[st1].sx[1]]-a[st1].li[a[st1].sx[2]];
			ji[2]--;
			i++;
		}
	}
	else{
		sort(club[3]+1,club[3]+ji[3]+1,cmp2);
		int i=1;
		while(ji[3]>n/2){
			int st1=club[3][i];
			ans-=a[st1].li[a[st1].sx[1]]-a[st1].li[a[st1].sx[2]];
			ji[3]--;
			i++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
