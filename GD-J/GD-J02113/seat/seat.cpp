#include<bits/stdc++.h> 
using namespace std;
int b[105],c[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	int ans1;
	ans1=n*m;
	for(int i=1;i<=ans1;i++){
		scanf("%d", &b[i]);
	}
	int w,t;
	w=b[1];
	sort(b+1,b+ans1+1);
	for(int i=1,j=ans1;i<=ans1;i++,j--){
		c[j]=b[i];
	}
	for(int i=1;i<=ans1;i++){
		if(c[i]==w){
			t=i;
			break;
		}
	}
	cout<<(t/n)+1<<" "<<t%m;
	return 0;
}
