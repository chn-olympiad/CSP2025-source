#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,a1,ji,sh,yu,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
        if(i==1)a1=a[i];
    }
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;--i){
        ++l;
        if(a[i]==a1)ji=l;
    }
    sh=ji/n;yu=ji%n;
    if(yu)++sh;
    if(yu==0){
        if(sh%2==1){
            yu=n;
        }else{
            yu=1;
        }
    }else{
        if(sh%2==0){
            yu=n-yu+1;
        }
    }
    cout<<sh<<" "<<yu;
	return 0;
}
