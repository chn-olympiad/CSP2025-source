#include<iostream>
using namespace std;
int n,q;
string a[100005],b[100005];
string as[100005],bs[100005];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		string h,d;
		int k=a[i].size(),f=b[i].size();
		for(int j=0;j<k;j++){
			if(a[i][j]==a[i][k-j]==b[i][j]==b[i][f-j]){
				as[i]+=a[i][j];
			}else{
				for(int o=j;o<=k-j-1;o++){
					h+=a[i][o];
				}
				for(int o=j;o<=f-j-1;o++){
//					cout<<o<<endl;
					d+=b[i][o];
				}
//				cout<<d<<" "<<h<<" "<<as[i]<<endl;
				break;
			}
		}
		a[i]=h;
		b[i]=d;
	}
	for(int i=1;i<=q;i++){
		string l,k;
		cin>>l>>k;
		string h,d;
		int y=l.size(),f=k.size();
		for(int j=0;j<f;j++){
			if(l[j]==l[y-j]==k[j]==k[f-j]){
				bs[i]+=l[j];
			}else{
				for(int o=j;o<=y-j-1;o++){
					h+=l[o];
				}
				for(int o=j;o<=f-j-1;o++){
//					cout<<o<<endl;
					d+=k[o];
				}
//				cout<<d<<" "<<h<<endl;
				break;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(a[j]==h&&b[j]==d){
				string v;
				int k=bs[i].size()-as[j].size();
				int q=bs[i].size();
//				cout<<k<<" "<<q<<endl;
				for(;k<=q;k++){
					v+=bs[k];
				}
//				cout<<v<<endl;
				if(v==as[j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

