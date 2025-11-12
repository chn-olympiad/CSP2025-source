#include <bits/stdc++.h>
using namespace std;
int jh[2000];
struct A{
	long long whic;
	long long a,b,c,maxnum;
}gh[200000];
bool cmp(A d,A e){
    return d.maxnum>=e.maxnum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n=0;
	cin>>n;
	long long m=0;
	while(n--){
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>gh[i].a>>gh[i].b>>gh[i].c;
			gh[i].maxnum=max(max(gh[i].a,gh[i].b),gh[i].c);
			if(gh[i].maxnum==gh[i].a){
				gh[i].maxnum=min(gh[i].maxnum-gh[i].b,gh[i].maxnum-gh[i].c);
				gh[i].whic=1;
			}else if(gh[i].maxnum==gh[i].b){
				gh[i].whic=2;
				gh[i].maxnum=min(gh[i].maxnum-gh[i].a,gh[i].maxnum-gh[i].c);
			}else{
				gh[i].whic=3;
				gh[i].maxnum=min(gh[i].maxnum-gh[i].a,gh[i].maxnum-gh[i].b);
			}
		}
		sort(gh+1,gh+m+1,cmp);
		int length=0;
		for(int i=1;i<=m;i++){
			if(jh[gh[i].whic]<m/2){
				if(gh[i].whic==1){
					length+=gh[i].a;
				}else if(gh[i].whic==2){
					length+=gh[i].b;
				}else{
					length+=gh[i].c;
				}
				jh[gh[i].whic]++;
			}else{
				if(gh[i].whic==1){
					length+=max(gh[i].b,gh[i].c);
					if(gh[i].b==max(gh[i].b,gh[i].c)){
						jh[2]++;
					}else{
						jh[3]++;
					}
				}else if(gh[i].whic==2){
					length+=max(gh[i].a,gh[i].c);
					if(gh[i].a==max(gh[i].a,gh[i].c)){
						jh[1]++;
					}else{
						jh[3]++;
					}
				}else{
					length+=max(gh[i].a,gh[i].b);
					if(gh[i].a==max(gh[i].b,gh[i].a)){
						jh[1]++;
					}else{
						jh[2]++;
					}
				}
			}
		}
		jh[1]=0;jh[2]=0;jh[3]=0;
		cout<<length<<endl;
	}
	return 0;
}
