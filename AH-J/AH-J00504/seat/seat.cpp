#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m;
int r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+len+1,cmp);
	int l=1,h=1;
	int bz=0;
	for(int i=1;i<=len;i++){
		if(a[i]==r){
			cout<<l<<" "<<h<<endl;
			return 0;
		}
		if(i%n==0){
			bz^=1;
			l++;
		}else{
			if(bz==0){
				h++;
			}else{
				h--;
			}
		}
	}
	return 0;
}

