
#include <stdio.h>
using namespace std;
int main(int argc, char **argv)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a=[1000];
	int s=0;
	int n;
	cin>>a;
	for(int i=0;i<=a;i++){
		if(a[i]>=0&&a[i]<=9){
			s+=a[i];
			c++;
		}
	}
	cout<<s;
	return 0;
}

