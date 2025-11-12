#include<bits/stdc++.h>
using namespace std;
int m,n;
int o;
void t(int a,int b,int v){
	//cout<<a<<' '<<b<<endl;
	if(v==o){
		cout<<a<<' '<<b;
		return;
	}
	v++;
	bool mm=a==m;
	bool nn=b%2;
	if(nn==0){
		mm=a==1;
	}
	if(nn==1&&mm==0){
		a++;
	}else if(nn==0&&mm==0){
		a--;
	}else{
		b++;
	}
	t(a,b,v);
	return;
}
int s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>s[i];
	}
	int g=s[1];
	sort(s+1,s+m*n+1);
	for(int i=1;i<=100;i++){
		if(s[i]==g){
			o=i;
			break;
		}
	}
	o=m*n-o+1;
	t(1,1,1);
	return 0;
}
