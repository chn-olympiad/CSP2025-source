#include<bits/stdc++.h>
using namespace std;
struct s{
	int n,m;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int l,k,a[5000000]={},h=0,p=0,d=-10,no[5000000]={},oo=0;
	s t[5000000]={};
	cin>>l>>k;
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	for(int i=0;i<l;i++){
		int ans=a[i];
		if(ans==k){
			t[h].n=i;
			t[h].m=i;
			h++;
		}
		for(int j=i+1;j<l;j++){
			ans^=a[j];
			if(ans==k){
				t[h].n=j;
				t[h].m=i;
				h++;
			}
		}
	}
	for(int i=0;i<l-1;i++){
		for(int j=0;j<l-1;j++){
			if(t[j].n+i==t[j].m){
				int ok=1;
				for(int o=0;o<oo;o++){
					if(t[j].n<=no[o]&&t[j].m>=no[o]) ok=0;
				}
				if(ok){
					for(int o=t[j].n;o<=t[j].m;o++){
						no[oo]=o;
						oo++;
					}
					p++;
				}
			}
		}
	}
	cout<<p;
	return 0;
}