#include<bits/stdc++.h>
using namespace std;
struct test{
	int cj,bh;
}stud[200];
bool cmp(test s1,test s2){return s1.cj>s2.cj;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	bool flag=1;
	cin>>n>>m;
	int cfj=n*m;
	for(int i=1;i<=cfj;i++){
		cin>>stud[i].cj;
		stud[i].bh=i;
	}
	sort(stud+1,stud+cfj+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(stud[++cnt].bh==1){
					cout<<i<<" "<<j;
					flag=0;
					break;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				if(stud[++cnt].bh==1){
					cout<<i<<" "<<j;
					flag=0;
					break;
				}
			}
		}
		if(flag==0)break;
	}
	return 0;
}
//R
