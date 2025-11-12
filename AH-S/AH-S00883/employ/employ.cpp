#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m;
string st;
int a[N];
int ans;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>st;
    for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			ans++;
		}
	}
	int l=st.size();
	bool t=false;
	for(int i=0;i<l;i++){
		if(st[i]=='1'){
			t=true;
			break;
		}
	}
    if((m==1)&&t){
		long long s=n-ans;
		for(int i=1;i<n;i++){
			s=s*(n-i);
		}
		cout<<s<<endl;
	}
	else{
		cout<<0<<endl;
	}
    fclose(stdin);
	fclose(stdout);
    return 0;
}
