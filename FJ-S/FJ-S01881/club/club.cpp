#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(club.in,"r",stdin);
	freopen(club.out,"w",stdout);
	int t;
	cin >> t;
	int ms[t];
	ms[1]=0;
	for(int i=1;i<=t;i++){
		int n,big=0;
		cin >> n;
		int s[n][3],now[3]={0,0,0};
		int nm=n/2;
		int p[3],p1,p2,p3,id;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin >> s[j][k];
				p[k]=s[j][k];
			}
			p1=p[1],p2=p[2],p3=p[3];
			int now1=now[1],now2=now[2],now3=now[3];
			int n=max(p1,p2);
			int m=max(n,p3);
			if(p1==p2){
				if(now1>now2){
					now2++;
					id==2;
				}
				else{
					now1++;
					id==1;
				}
			}
			else if(p1==p3){
				if(now1>now3){
					now3++;
					id==3;
				}
				else{
					now1++;
					id==1;
				}
			}
			else if(p3==p2){
				if(now3>now2){
					now2++;
					id==2;
				}
				else{
					now3++;
					id==3;
				}
			}
			else if(m==p1){
				if(now1<nm){
					now1++;
					id=1;
				}
				else{
					int b=max(p2,p3);
					if(now2<nm){
						now2++;
						id=2;
					}
					else now3++;id=3;
				}
			}
			else if(m==p2){
				if(now2<nm){
					now2++;
					id=2;
				}
				else{
					int b=max(p1,p3);
					if(now1<nm){
						now1++;
						id=1;
					}
					else now3++;id=3;
				}
			}
			else if(m==p3){
				if(now3<nm){
					now3++;
					id=3;
				}
				else{
					int b=max(p2,p1);
					if(now2<nm){
						now2++;
						id=2;
					}
					else now1++;id=1;
				}
			}
			ms[i]+=p[id];
			ms[i+1]=0;
		}
		
	}
	for(int i=1;i<=t;i++){
		cout << ms[i] << endl;
	}
	return 0;
}
