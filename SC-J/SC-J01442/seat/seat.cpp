#include <bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int a[N],n,m,k=1,l;
int b(int g,int h){
	return g>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	int t=a[0];
	for(int i=1;i<n*m;i++)
		cin>>a[i];
	sort(a,a+n*m,b);
	for(int i=0;i<n*m;i++){
		if(a[i]==t)
		{
			int q=1,cnt=1;
			while(q<i+1){
				q+=n;
				cnt++;
			} 
			k=cnt;

			if((i+1)%n==0)
				l=n;
			else
				l=(i+1)%n;			
			if(k%2==0){
				l=n-l+1;
			}
		}
	}
	cout<<k<<" "<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}