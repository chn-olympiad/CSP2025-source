#include<iostream>
using namespace std;
int main(){
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	int n,d,j,k;
	int a[5000];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	for(int q=i;q<n-2;q++)
		for(int w=q+1;w<n-1;w++)
			for(int e=w+1;e<n;e++){
				d=max(a[q],max(a[w],a[e]));
				if(a[q]+a[w]+a[e]>d)j++;
			}
	for(int i=0;i<n;i++)
	for(int q=i;q<n-3;q++)
		for(int w=q+1;w<n-2;w++)
			for(int e=w+1;e<-1;e++)
				for(int r=e+1;r<n;r++){
					d=max(a[q],max(a[w],max(a[e],a[r])));
					if(a[q]+a[w]+a[e]+a[r]>d)j++;
			}
	for(int i=0;i<n;i++)
	for(int q=i;q<n-4;q++)
		for(int w=q+1;w<n-3;w++)
			for(int e=w+1;e<n-2;e++)
				for(int r=e+1;r<n-1;r++)
					for(int t=r+1;t<n;t++){
						d=max(a[q],max(a[w],max(a[e],max(a[r],a[t]))));
						if(a[q]+a[w]+a[e]+a[r]+a[t]>d)j++;
			}
	cout<<j%998%244%353;
	return 0;
}
