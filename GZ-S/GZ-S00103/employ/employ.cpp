//GZ-S00103 毕节梁才学校 周天诚 
#include<bits/stdc++.h>

using namespace std;


int n,m,k;






int main(int argc, char** argv) {
	freopen("employ.in","r","stdin");
	freopen("employ.out","w","stdout");
	int n,a[100];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int i=0;
	while(i<n)
	{
		if(a[i]%10<5) a[i]=a[i]-a[i]%10;
		if(a[i]%10>4) a[i]=a[i]+(10-a[i]%10);
		if(a[i]%10==0) a[i]=a[i];
		i++;
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<endl;
	return 0;
}
