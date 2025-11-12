#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a_1,a_2,a_3,k=0;
}lis[100005];
bool cmp(stu a,stu b){
	return a.k>=b.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,id=0;
	long long list[100000]={};
	cin>>n;
	int abcd=n;
	while(n--){
		int m;
		cin>>m;
		int li[4]={0};
		int cnt=0;
		for(int i=0;i<m;i++){
			cin>>lis[i].a_1>>lis[i].a_2>>lis[i].a_3;
			lis[i].k=abs(lis[i].a_1-lis[i].a_2)+abs(lis[i].a_2-lis[i].a_3);
		}
		sort(lis,lis+m,cmp);
		for(int i=0;i<m;i++){
			int x=max(lis[i].a_1,max(lis[i].a_2,lis[i].a_3));
			if(x==lis[i].a_1){
				if(li[0]+1<=m/2){
					li[0]++;
					cnt+=x;
				}
				else{
					x=max(lis[i].a_2,lis[i].a_3);
					if(x==lis[i].a_2&&li[1]+1<=m/2){
						cnt+=x;
						li[1]++;
					}
					else{
						li[2]++;
						cnt+=lis[i].a_3;
					}
				}
			}
			else if(x==lis[i].a_2){
				if(li[1]+1<=m/2){
					li[1]++;
					cnt+=x;
				}
				else{
					x=max(lis[i].a_1,lis[i].a_3);
					if(x==lis[i].a_1&&li[0]+1<=m/2){
						cnt+=x;
						li[0]++;
					}
					else{
						li[2]++;
						cnt+=lis[i].a_3;
					}
				}
			}
			else if(x==lis[i].a_3){
				if(li[2]+1<=m/2){
					li[2]++;
					cnt+=x;
				}
				else{
					x=max(lis[i].a_2,lis[i].a_1);
					if(x==lis[i].a_1&&li[0]+1<=m/2){
						cnt+=x;
						li[0]++;
					}
					else{
						li[1]++;
						cnt+=lis[i].a_2;
					}
				}
			}
		}	
		list[id]=cnt;
		id++;
	}
	for(int i=0;i<abcd;i++){
		cout<<list[i]<<endl;
	}
	return 0;
}