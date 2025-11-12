//GZ-S00158 遵义市第十二中学  张晋宁 
#include <bits/stdc++.h>
using namespace std;
int sum;
int a[100001],b[100001],c[100001],a1=1,b1=1,c1=1,a2=99999,b2=99999,c2=99999,a3,b3,c3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n){
		
		int s;
		cin>>s;
		int d[s][3];
		for(int i=1;i<=s;i++){
			cin>>d[i][1]>>d[i][2]>>d[i][3];
			if(d[i][1]>=d[i][2]){
				if(d[i][1]>=d[i][3]){
					if(d[i][1]>=a[i]){
						a[a1]=d[i][1];
						if(a[a1]<a2){
							a3=i;
							a2=a[a1];
						}
						a1++;
						if(a1>s/2){
							a1=1;
						}
					}
					else{
						d[i][1]=0;
					}
					
				}
			}
			if(d[i][2]>=d[i][1]){
				if(d[i][2]>=d[i][3]){
					if(d[i][2]>=b[i]){
						b[b1]=d[i][2];
						if(b[b1]<b2){
							b3=i;
							b2=b[b1];
						}
						b1++;
						if(b1>s/2){
							b1=1;
						}
					}
					else{
						d[i][2]=0;
					}
				}
			}
			if(d[i][3]>=d[i][1]){
				if(d[i][3]>=d[i][2]&&d[i][3]>=c[i]){
					c[c1]=d[i][3];
					if(c[c1]<c2){
						c3=i;
						c2=c[c1];
					}
					c1++;
					if(c1>s/2+1){
						c1=1;
					}
				}
					
			}
		}
		for(int i=1;i<=s/2;i++){
			sum+=a[i]+b[i]+c[i];
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		n--;
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
