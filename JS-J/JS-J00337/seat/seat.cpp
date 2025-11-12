#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],ans,g;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>g;
	a[1]=g;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		}
	sort(a+1,a+n*m+1,greater<int>());
	int tmp;
	for(int i=1;i<=n*m;i++){
		if(a[i]==g){
			tmp=i;
			break;
		}
	}
	int shang,yu;
	shang=tmp/n;
	yu=tmp%n;
	//cout<<shang<<" "<<yu;
	if((yu==0)&&(shang&1))
	{
		cout<<shang<<" "<<n;
		return 0;
	}
	if(yu==0)
	{
		cout<<shang<<" "<<1;
		return 0;
	}
	if(shang&1)
	{
		cout<<shang+1<<" "<<n-yu+1;
		return 0;
	}
	cout<<shang+1<<" "<<yu;
	return 0;
}
