#include <bits/stdc++.h>
using namespace std;
struct group{
	string a;
	string b;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	group r[n];
	for(int i=0;i<n;i++){
		cin>>r[i].a>>r[i].b;
	}
	group qu[q];
	for(int i=0;i<q;i++){
		cin>>qu[i].a>>qu[i].b;
	}
	for(int j=0;j<q;j++){
		int sum=0;
		for(int i=0;i<n;i++){
			if(r[i].a==qu[j].a && r[i].b==qu[j].b)sum++;
				for(int w=0;w<qu[j].a.size()-4;w++){
					if((r[i].a[0]==qu[i].a[0] && r[i].a[1]==qu[i].a[1]) && (r[i].b[0]==qu[i].b[0] && r[i].b[1]==qu[i].b[1]))sum++;
			}
			
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
