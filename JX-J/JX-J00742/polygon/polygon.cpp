#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int a[5005],s[5005],b[5005];
bool f(int na,int nb,int nc){
	int maxn=max(na,max(nb,nc));
	if((na+nb+nc)>maxn*2)return 1;
	return 0;
}
int main(){
    //freopen("number.in","r",stdin);                                          
    //freopen("number.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int num1=0;num1<n-2;num1++){
		for(int num2=num1+1;num2<n-1;num2++){
			for(int num3=num2+1;num3<n;num3++){
				if(f(a[num1],a[num2],a[num3]))cnt++;
			}
		}
	}
	cout<<cnt*3;
    return 0;
}
