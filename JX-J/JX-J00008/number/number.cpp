#include <iostream>
#include <cstring>
using namespace std;

int k[13];
int n=0;
char a[1000050];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (int i=0;i<=strlen(a);i++){
        if ('0'<=a[i]&&a[i]<='9'){
            k[a[i]-'0']++;
        }
	}
	for(int i=9;i>=0;i--){
        for(int j=1;j<=k[i];j++){
            cout<<i;
        }
	}

	return 0;

}
