#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int n,num[N] = {0};
int a[N],b[N],c[N];
bool str(int a,int b){
	return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
		int f = 1;
		cin >> n;
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(b[i]!=0||c[i]!=0)f = 0;
		}
		if(f){
			sort(a+1,a+n+1,str);
			int sum = 0;
			for(int i = 1;i<=n/2;i++)sum+=a[i];
			cout << sum << endl;
		}else{
			int sum = 0;
			for(int i = 1;i<=n;i++){
				sum+=max(a[i],max(b[i],c[i]));
			}
			cout << sum;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
