#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt;
int a[150];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=x;i>=1;i--){
		if(a[i]==r){
			cnt=i;
			break;
		}
	}
	if(cnt%(n*2)==0){
        prtinf("%d %d",cnt/n,1);
	}
	else if(cnt%n==0){
        prtinf("%d %d",cnt/n,n);
	}
	else{
        int mod=cnt%(n*2);
        if(mod<=n){
            prtinf("%d %d",cnt/n+1,mod);
        }
        else {n*2-mod+1
            prtinf("%d %d",cnt/n,1);
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
