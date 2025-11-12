#include<bits/stdc++.h>
using namespace std;
int a[100002][4];
int a3[4];
int end[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n=0,cnt=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			int l=0,f=0;
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			l=max(a[j][1],max(a[j][2],a[j][3]));
			cnt+=l;
			if(l=a[j][1]) a3[1]+=1;
			else if(l=a[j][2]) a3[2]+=1;
			else  a3[3]+=1;
			int m=n/2;
			if(a3[1]<=m||a3[2]<=m||a3[3]<=m) continue;
			else if(a3[1]>m){
				a3[1]-=1;
				f=max(a[j][2],a[j][3]);
				cnt=cnt-l+f;
			 if(f=a[j][2]) {
				    a3[2]+=1;
				}
				else{
				    a3[2]+=1;
				} 
			}
			else if(a3[2]>m){
				a3[2]-=1;
				f=max(a[j][1],a[j][3]);
				cnt=cnt-l+f;
			if(f=a[j][1]) {
				    a3[1]+=1;
				}
				else{
				    a3[3]+=1;
				} 
			}
			else{
				a3[3]-=1;
				f=max(a[j][1],a[j][2]);
				cnt=cnt-l+f;
				if(f=a[j][1]) {
				    a3[1]+=1;
				}
				else{
				    a3[2]+=1;
				} 
			}
		}end[i]=cnt;
	}
		
		
    for(int i=1;i<=t;i++) cout<<end[i]<<endl;
	return 0;
}
