#include<bits/stdc++.h>
using namespace std;
const int N=1000000+5;
struct stu{
	int mis,mad,to;
}we[N];
int n,m;
bool cmp(stu a,stu b){
	return a.mad-a.mis<b.mad-b.mis;
}
void main1(){
	long long ans=0;int go=0,re[5]={};
	cin>>n;
	for(int i=1;i<=n;++i){
		int x,y,z,to;
		cin>>x>>y>>z;
		int mad=max(x,max(y,z));
		if(mad==x){
			to=1;
		}else if(mad==y){
			to=2;
		}else{
			to=3;
		}
		int mis=x+y+z-mad-min(x,min(y,z));
		we[i]={mis,mad,to};
		re[to]++;
		ans+=mad;
	}
	for(int i=1;i<=3;i++){
		if(re[i]>n/2){
			go=i;
			break;			
		}
	}
	if(go!=0){
		sort(we+1,we+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(we[i].to==go){
				ans+=we[i].mis-we[i].mad;
				--re[go];
				if(re[go]==n/2){
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		main1();
	}
}
/*
T1 was difficult for me QAQ
I spent 1h to finish it;
I'm jh13h 
*/
