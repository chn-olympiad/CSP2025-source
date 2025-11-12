#include<bits/stdc++.h>
#define int long long
int mp[11][11];
struct stu{
    int score=0,id=0;
    bool isr=0;
}a[10001];
bool cmp(stu x,stu y){
    return x.score>y.score;
}
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
        cin>>a[i].score;
        a[i].isr=0;
	}
	a[1].isr=1;
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=m*n;i++){
        a[i].id=i;
	}
	for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=(i-1)*n+1;j<=i*n;j++){
                if(a[j].isr==1){
                    cout<<i<<" "<<(j%n?j%n:n);
                    return 0;
                }
            }
        }else{
            for(int j=i*n;j>=(i-1)*n+1;j--){
                if(a[j].isr==1){
                    cout<<i<<" "<<(j%n?n-j%n+1:1);
                    return 0;
                }
            }
        }
	}
	return 0;
}
