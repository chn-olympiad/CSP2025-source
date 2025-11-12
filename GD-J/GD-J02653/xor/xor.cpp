#include<bits/stdc++.h>
using namespace std;
struct LL{
	int l;
	int r;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<LL> v;
	int n,k,s=0,ss=0;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int x=0,xx=1;
			for(int w=i;w<=j+i;w++){
				x=x^a[w];
			}
			
//			cout<<"["<<i<<","<<j+i<<"]  x="<<x;
//			if(x==k)cout<<"   ss="<<++ss;
			if(x==k){
				for(int y=0;y<v.size();y++){
					if((v[y].l<=i&&v[y].r>=i+j)||(i<=v[y].l&&i+j>=v[y].r)){
						
//						if(v[y].l<=i&&v[y].r>=i+j)cout<<v[y].l<<"<="<<i<<"&&"<<v[y].r<<">="<<i+j<<endl;
//						else cout<<i<<"<="<<v[y].l<<"&&"<<i+j<<">="<<v[y].r<<endl;
						xx=0;
						break;
					}
				}
				if(xx==1){
//					cout<<"----¶Ô";
//					cout<<"["<<i<<","<<j+i<<"]"<<endl;
					s++;
					v.push_back({i,i+j});	
				}//else cout<<"----------´í";
				
			}
//			cout<<endl;
		}
	}
	cout<<s;
	return 0;
} 
