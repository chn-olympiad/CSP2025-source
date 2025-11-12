#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	freopen("poligon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int s=1;
	int c=0;
	cin>>n;
	int max=0;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	max=max*2;
	for(int i=0;i<n;i++){
		ans+=a[i];
	}
	if(ans>max){
		cout<<s;
	}else{
		cout<<c;
	}
	return 0;
}
