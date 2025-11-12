#include<bits/stdc++.h>
using namespace std;
int n,m,xans,yans,w;
int a[105];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==w){
			w=i;
			break;
		}
	}
	xans=(w%n==0?w/n:w/n+1);
	if(xans%2==1){
		yans=w-n*(xans-1);
	}else{
		yans=n*xans-w+1;
	}cout<<xans<<" "<<yans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
