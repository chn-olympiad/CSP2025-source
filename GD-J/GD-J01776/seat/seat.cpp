#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;//n,r行数，m,c列数 
	cin>>n>>m;
	int a[n*m+10];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];//小R成绩
	for(int i=0;i<n*m;i++){
		int Max=0,num=0;
		for(int j=i;j<n*m;j++){
			if(a[j]>Max){
				Max=a[j];
				num=j;
			}
		}
		int z=a[i];
		a[i]=a[num];
		a[num]=z;
	}
	int cnt=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==R){
			cnt=i+1;
			break;
		}
	} 
	if(cnt%n==0){
		c=cnt/n;
		r=m;
	}else{
		c=cnt/n+1;
		if(c%2==0){
		    r=m-cnt%n+1;
	    }else{
		    r=cnt%n;
	    }
	}	
	cout<<c<<' '<<r<<endl;
	return 0;
}
