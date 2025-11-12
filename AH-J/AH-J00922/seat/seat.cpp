#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,pos=1;
long long a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]) pos++;
    }
    long long h=pos%n;
    if(h==0) h=n;
    long long l=(pos+n-1)/n;
    if(l%2==0){
        cout<<l<<" "<<n-h+1;
    }else{
        cout<<l<<" "<<h;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
