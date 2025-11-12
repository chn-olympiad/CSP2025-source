#include <bits/stdc++.h>
using namespace std;
struct node{
	int score,name;
};
bool cmp(node x,node y){
	return x.score<y.score;
}
int a[200002][4]={};
vector<vector<node> >s(4);
int t,n,rma=0,ans=0,sma[5]={};
int d(int i,int w){
	int p1=INT_MIN,p2=0,p3=INT_MAX;
	for(int j=1;j<=3;j++){
		p1=max(a[i][j],p1);
		p3=min(a[i][j],p3);
		p2+=a[i][j];
	}
	p2-=p1+p3;
	for(int j=1;j<=3;j++){
		if(w==1&&a[i][j]==p1) return j;
		if(w==2&&a[i][j]==p2) return j;
		if(w==3&&a[i][j]==p3) return j;
	}
}
void f(int i,int ji){
	if(ji==3){
		int want2=d(i,3);
		ans+=a[i][want2];
		s[want2].push_back({a[i][want2],i});
		sma[want2]++;
		sort(s[want2].begin(),s[want2].end(),cmp);
		return;
	}
	int want=d(i,ji);
	if(sma[want]<rma){
		ans+=a[i][want];
		s[want].push_back({a[i][want],i});
		sma[want]++;
		sort(s[want].begin(),s[want].end(),cmp);
		//cout<<i<<"加"<<want<<endl;
	}
	else{
		int li=s[want][0].name;
		int lwant;
		for(int i=1;i<=3;i++){
			lwant=d(li,i);
			if(sma[lwant]<rma){
				break;
			}
		}
		//cout<<want<<" "<<lwant<<endl;
		if(ans>=ans-a[li][want]+a[li][lwant]+a[i][want]){
			f(i,ji+1);
		}
		else{
			ans-=a[li][want];
			ans+=a[li][lwant];
			ans+=a[i][want];
			s[want].erase(s[want].begin());
			s[want].push_back({a[i][want],i});
			s[lwant].push_back({a[li][lwant],i});
			sort(s[want].begin(),s[want].end(),cmp);
			sort(s[lwant].begin(),s[lwant].end(),cmp);
			//cout<<i<<"加"<<want<<"踢"<<li<<endl;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		rma=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			f(i,1);
		}
		cout<<ans<<endl;
		memset(sma,0,sizeof(sma));
		for(int i=1;i<=3;i++){
			while(s[i].empty()==false){
				s[i].erase(s[i].begin());
			}
		}
		ans=0;
	}
}