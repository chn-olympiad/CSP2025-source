#include<iostream>
#include<cstring>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
bool a2[100005],b2[100005],c2[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int s=0;
		memset(a2,0,sizeof(a2));
		memset(b2,0,sizeof(b2));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n/2;i++){
			int q=-1;
			for(int j=0;j<n;j++) if(a2[j]==0&&(q==-1||max(a[j]-b[j],a[j]-c[j])>max(a[q]-b[q],a[q]-c[q]))) q=j;
			a2[q]=1;
			
		}
		for(int i=1;i<=n/2;i++){
			int q=-1;
			for(int j=0;j<n;j++) if(b2[j]==0&&(q==-1||max(b[j]-a[j],b[j]-c[j])>max(b[q]-a[q],b[q]-c[q]))) q=j;
			b2[q]=1;
		}
		for(int i=1;i<=n/2;i++){
			int q=-1;
			for(int j=0;j<n;j++) if(c2[j]==0&&(q==-1||max(c[j]-b[j],c[j]-a[j])>max(c[q]-b[q],c[q]-a[q]))) q=j;
			c2[q]=1;
		}
		for(int d=0;d<n;d++){
			if(a2[d]&&!b2[d]&&!c2[d]) s+=a[d];
			else if(!a2[d]&&b2[d]&&!c2[d]) s+=b[d];
			else if(!a2[d]&&!b2[d]&&c2[d]) s+=c[d];
			else if(!a2[d]&&b2[d]&&c2[d]){
				if(b[d]>c[d]) s+=b[d];
				else s+=c[d];
			}else if(a2[d]&&!b2[d]&&c2[d]){
				if(a[d]>c[d]) s+=a[d];
				else s+=c[d];
			}else if(a2[d]&&b2[d]&&!c2[d]){
				if(b[d]>a[d]) s+=b[d];
				else s+=a[d];
			}else{
				if(a[d]>b[d]){
					if(a[d]>c[d]) s+=a[d];
					else s+=c[d];
				}else{
					if(b[d]>c[d]) s+=b[d];
					else s+=c[d];
				}
			} 
		}
		for(int i=0;i<n;i++) cout<<a2[i]<<" "<<b2[i]<<" "<<c2[i]<<endl;
		cout<<s<<endl;
	}
	return 0;
}
