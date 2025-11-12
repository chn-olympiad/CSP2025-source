#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;cin>>n;
	int m;cin>>m;
	int num=0;
	int x=0;
	int sum=0;
	string s;cin>>s;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int a=1;
	for(int i=1;i<=n;i++){
		a*=i;
	}
	int b=0;
	for(int z=0;z<a;z++){
		for(int i=0;i<n;i++){
			if(s[i]=='1'&&x<c[i]){
				num++;
			}else{
				x++;
			}
		}
		if(num>=m){
			sum++;
		}
		b++;
		if(b==n){
			b=1;
		}
		swap(c[n-b],c[n-b-1]);
		num=0;
		x=0;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
