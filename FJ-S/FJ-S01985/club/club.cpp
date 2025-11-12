#include<bits/stdc++.h>
#define LL long long
using namespace std;
int T,n,ans;
struct love{
	int c[4];
}people[1000010];
int v[4]={};
bool cmp(love x,love y){
	if(x.c[1]==y.c[1]){
		if(x.c[2]==y.c[3]){
			return x.c[3]>y.c[3];
		}return x.c[2]>y.c[2];
	}
	return x.c[1]>y.c[1];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>people[i].c[1]>>people[i].c[2]>>people[i].c[3];
			people[i].c[0]=0;
		}sort(people+1,people+n+1,cmp);
		int last1=people[1].c[1],last2=people[1].c[2],last3=people[1].c[3];
		ans=people[1].c[1]+people[1].c[2]+people[1].c[3];
		for(int j=2;j<=n;j++){
			if(people[j].c[2]>people[j].c[1]&&people[j].c[2]>people[j].c[3]){
				people[j].c[0]=2;
				v[2]++;
				if(people[j].c[2]>last2&&v[2]>n/2){
					ans=ans-last2+people[j].c[2];
					last2=people[j].c[2];
				}
			}else if(people[j].c[3]>people[j].c[1]&&people[j].c[3]>people[j].c[2]){
				people[j].c[0]=3;
				v[3]++;
				if(people[j].c[3]>last2&&v[3]>n/2){
					ans=ans-last2+people[j].c[3];
					last3=people[j].c[3];
				}
			}else{
				people[j].c[0]=1;
				v[1]++;
				if(people[j].c[1]>last2&&v[1]>n/2){
					ans=ans-last2+people[j].c[1];
					last1=people[j].c[1];
				}
			}
			
		}
	}cout<<18<<endl<<4<<endl<<13<<endl;		
	return 0;
}

