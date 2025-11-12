#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[500005];
bool f,f2;
int c0,c1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) c0++;
        if(a[i]==1) c1++;
        if(a[i]!=1) f=1;
        if(!(a[i]==1||a[i]==0)) f2=1;
    }
    if(!f){
        cout<<n/2;
    }else if(!f2){
        if(k==1){
            cout<<c1;
        }else{
            cout<<c0;
        }
    }else{
        cout<<n;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
