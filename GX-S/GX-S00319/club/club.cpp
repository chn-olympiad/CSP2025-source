#include<bits/stdc++.h>
using namespace std;
struct Nova{
	int w1,w2,w3;
	int man,woman,noman;
	int love,chazhi;
};
Nova t[100001];
long long ans;
int n,o;
int fb[4]={};
bool cmp(Nova a,Nova b){
	if(a.love==o&&b.love==o)return a.chazhi>b.chazhi; 
	return a.love==o;
}
void solve(){
	ans=0;
	fb[1]=0;
	fb[2]=0;
	fb[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].w1>>t[i].w2>>t[i].w3;
		t[i].man=max(t[i].w1,max(t[i].w2,t[i].w3));
		t[i].woman=min(t[i].w1,min(t[i].w2,t[i].w3));
		if(t[i].man==t[i].w1){
			t[i].love=1;
			if(t[i].woman==t[i].w2)t[i].noman=t[i].w3;
			else t[i].noman=t[i].w2;
		}
		if(t[i].man==t[i].w2){
			t[i].love=2;
			if(t[i].woman==t[i].w1)t[i].noman=t[i].w3;
			else t[i].noman=t[i].w1;
		}
		if(t[i].man==t[i].w3){
			t[i].love=3;
			if(t[i].woman==t[i].w1)t[i].noman=t[i].w2;
			else t[i].noman=t[i].w1;
		}
		fb[t[i].love]++;
		t[i].chazhi=t[i].man-t[i].noman;
	}
	if(fb[1]>=fb[2]&&fb[1]>=fb[3])o=1;
	else if(fb[2]>=fb[1]&&fb[2]>=fb[3])o=2;
	else if(fb[3]>=fb[1]&&fb[3]>=fb[2])o=3;
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(t[i].love==o){
			if(i<=n/2)ans+=t[i].man;
			else ans+=t[i].noman;
		}
		else ans+=t[i].man;
		t[i].love=0;
		t[i].man=0;
		t[i].noman=0;
		t[i].w1=0;
		t[i].w2=0;
		t[i].w3=0;
		t[i].woman=0;
		t[i].chazhi=0;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
