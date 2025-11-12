#include<bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int m;
	int cnt=0;
	int c=0;
	int f=0;
	int a[m];
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>a[i];
		cnt+=a[i];
		if(cnt>2*c){
			f++;
			}
		cout<<f;
	}
	 
	if(m<3){
		cout<<0;
	}
	while(m==3){
		if(a[0]+a[1]+a[2]>a[0]*2){
			cout<<1;
		}
		if(a[0]+a[1]+a[2]>a[1]*2){
			cout<<1;
		}
		if(a[0]+a[1]+a[2]>a[2]*2){
			cout<<1;
		}
		break;
	}
	if(cnt>2*c){
		f++;
		return 0; 
	}
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

