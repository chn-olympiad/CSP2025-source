#include<bits/stdc++.h>
using namespace std;
int a1[100005];
int a2[100005];
int a3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		int num=0;
		int r1=0,r2=0,r3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]&&r1<n/2){
				num+=a1[i];
				a1[i]=-100;
				r1++;
			}
			else if(a1[i]<=a2[i]&&a2[i]>=a3[i]&&r2<n/2){
				num+=a2[i];
				a2[i]=-100;
				r2++;
			}
			else if(a3[i]>=a2[i]&&a1[i]<=a3[i]&&r3<n/2){
				num+=a3[i];
				a3[i]=-100;
				r3++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}