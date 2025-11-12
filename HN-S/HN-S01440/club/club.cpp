#include<bits/stdc++.h>
using namespace std;
int main()
{
	feropen("club.in","r",stdin);
	feropen("club.out","w",stdout);
	int t,n,q2[1000],q3=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a1[1000],a2[1000],a3[1000],a=0,b=0,c=0,b1[1000],b2[1000];
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>a2[i]){
				if(a1[i]>a3[i]){
					a++;
					b1[i]=a1[i];
					if(a2[i]>a3[i]){
						b2[i]=a2[i];
					}else{
						b2[i]=a3[i];
					}
				}else{
					c++;
					b1[i]=a3[i];
					b2[i]=a1[i];
				}
			}else{
				if(a2[i]>a3[i]){
					b++;
					b1[i]=a2[i];
					if(a1[i]>a3[i]){
						b2[i]=a1[i];
					}else{
						b2[i]=a3[i];
					}
				}else{
					c++;
					b1[i]=a3[i];
					b2[i]=a2[i];
				}
			}
		}
		int z=0;
		for(int i=0;i<n;i++){
			z+=b1[i];
		}
		int q1[1000];
		if(a*2>n||b*2>n||c*2>n){
			for(int c=0;c<n;c++){
				q1[c]=z-b1[c]+b2[c];
			}
			for(int v=0;v<n;v++){
				for(int e=1;e<n;e++){
					sort(q1[e-1],q1[e]);
				}
			}
			q2[q3]=q1[1];
			q3++;
		}else{
			q2[q3]=z;
			q3++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<q2[i]<<endl;
	}
	return 0;
}
