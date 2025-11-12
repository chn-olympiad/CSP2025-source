#include <bits/stdc++.h>
using namespace std;
int n , m ,a[100000+5],b[100000+5],c[100000+5],b1,b2,b3,sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		sum=0;
		cin>>m;
		for(int j=0 ;j<m;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(max(a[j],max(b[j],c[j]))==a[j]){
				if(b1<n/2+1){
					sum+=a[j];
					b1++;
				}
				else{
					if(max(b[j],c[j])==b[j]){
						if(b2<n/2+1){
							sum+=b[j];
							b2++;
						}
						else{
							sum+=c[j];
							b3++;
						}
					}
				}
			}
			else if(max(a[j],max(b[j],c[j]))==b[j]){
				if(b2<n/2+1){
					sum+=b[j];
					b2++;
				}
				else{
					if(max(a[j],c[j])==a[j]){
						if(b1<n/2+1){
							sum+=a[j];
							b1++;
						}
						else{
							sum+=c[j];
							b3++;
						}
					}
				}
			}
			else if(max(a[j],max(b[j],c[j]))==c[j]){
				if(b3<n/2+1){
					sum+=c[j];
					b3++;
				}
				else{
					if(max(a[j],b[j])==a[j]){
						if(b1<n/2+1){
							sum+=a[j];
							b1++;
						}
						else{
							sum+=b[j];
							b2++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	} 
	return 0;
}
