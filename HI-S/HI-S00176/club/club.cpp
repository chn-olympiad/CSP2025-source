#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e5+10
#define ld long long
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	int n[t];
	for(int i=0;i<t;i++){
		int sum=0; 
		cin>>n[i];
		int s1=0,s2=0,s3=0;
		for(int j=0;j<n[i];j++){
			int a[3];	
			cin>>a[0]>>a[1]>>a[2];
			int b[t];
			b[0]=a[0];
			b[1]=a[1];
			b[2]=a[2];
			sort(b,b+3);
			if(b[2]==a[0]){
				s1++;
				if(s1<=n[i]/2){
				sum=sum+b[2];
			}else{
				if(s2<=n[i]/2){
					s1--;
					s2++;
					sum=sum+a[1];
				}else if(s3<=n[i]/2){
					s1--;
					s3++;
					sum=sum+a[2];
				}
			}
			}
			else if(b[2]==a[1]){
					s2++;
				if(s2<=n[i]/2){
					sum=sum+b[2];
				}else{
					if(s1<=n[i]/2){
					s2--;
					s1++;
					sum=sum+a[0];
					}else if(s3<=n[i]/2){
					s2--;
					s3++;
					sum=sum+a[2];
					}
				}
			}
			else if(b[2]==a[2]){
				s3++;
				if(s3<=n[i]/2){
					sum=sum+b[2];
				}else{
					if(s2<=n[i]/2){
					s3--;	
					s2++;
					sum=sum+a[1];
					}else if(s1<=n[i]/2){
					s3--;
					s1++;
					sum=sum+a[0];
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

