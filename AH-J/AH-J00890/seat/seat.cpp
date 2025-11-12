#include<bits/stdc++.h>
using namespace std;
struct stu{
	int fs,rw;
}a[400];
int n,m;
bool cmp(stu x,stu y){
	return x.fs>y.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].fs;
		if(i==0){
			a[i].rw=1;
		}else{
			a[i].rw=0;
		}
	}
	sort(a,a+n*m,cmp);
	int i=1,j=1,cnt=1;
	if(a[0].rw==1){
		cout<<1<<" "<<1;
		return 0;
	}
	while(1){
		if(j%2==1&&i!=n){
			i++;
		}else if(j%2==1&&i==n){
			j++;
		}else if(j%2==0&&i!=1){
			i--;
		}else if(j%2==0&&i==1){
			j++;
		}
		if(a[cnt].rw==1){
			cout<<j<<" "<<i;
			return 0;
		}
		cnt++;
	}
	return 0;
}
