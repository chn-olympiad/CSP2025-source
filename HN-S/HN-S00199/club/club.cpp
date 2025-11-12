#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("clup.in","r",stdin);
//	freopen("clup.out","w",stdout);
	int maxn,f,ans,t,n,a[100000][3],c1[50010],c2[50010],c3[50010],w3,w1,w2;
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		maxn=n/2;
		ans=0;
		w1=0;
		w2=0;
		w3=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] and a[i][1]>=a[i][2]){
				c1[w1]=a[i][0]-a[i][1];
				for(int q=w1;q>0;q--){
					if(c1[q]>c1[q-1]){
						f=c1[q];
						c1[q]=c1[q-1];
						c1[q-1]=f;
					}
					else{
						break;
					}
				}
				if(w1<maxn){
					w1++;	
				}
				else{
					ans-=c1[w1];
				}
				ans+=a[i][0];
			}
			else if(a[i][0]>=a[i][2] and a[i][2]>=a[i][1]){
				c1[w1]=a[i][0]-a[i][2];
				for(int q=w1;q>0;q--){
					if(c1[q]>c1[q-1]){
						f=c1[q];
						c1[q]=c1[q-1];
						c1[q-1]=f;
					}
					else{
						break;
					}
				}
				if(w1<maxn){
					w1++;	
				}
				else{
					ans-=c1[w1];
				}
				ans+=a[i][0];
			}
			else if(a[i][1]>=a[i][0] and a[i][1]>=a[i][2]){
				c2[w2]=a[i][1]-a[i][0];
				for(int q=w2;q>0;q--){
					if(c2[q]>c2[q-1]){
						f=c2[q];
						c2[q]=c2[q-1];
						c2[q-1]=f;
					}
					else{
						break;
					}
				}
				if(w2<maxn){
					w2++;	
				}
				else{
					ans-=c2[w2];
				}
				ans+=a[i][1];
			}
			else if(a[i][1]>=a[i][2] and a[i][1]>=a[i][0]){
				c2[w2]=a[i][1]-a[i][2];
				for(int q=w2;q>0;q--){
					if(c2[q]>c2[q-1]){
						f=c2[q];
						c2[q]=c2[q-1];
						c2[q-1]=f;
					}
					else{
						break;
					}
				}
				if(w2<maxn){
					w2++;	
				}
				else{
					ans-=c2[w2];
				}
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][1] and a[i][1]>=a[i][0]){
				c3[w3]=a[i][2]-a[i][1];
				for(int q=w3;q>0;q--){
					if(c3[q]>c3[q-1]){
						f=c3[q];
						c3[q]=c3[q-1];
						c3[q-1]=f;
					}
					else{
						break;
					}
				}
				if(w3<maxn){
					w3++;	
				}
				else{
					ans-=c3[w3];
				}
				ans+=a[i][2];
			}
			else {
				c3[w3]=a[i][2]-a[i][0];
				for(int q=w3;q>0;q--){
					if(c3[q]>c3[q-1]){
						f=c3[q];
						c3[q]=c3[q-1];
						c3[q-1]=f;
					}
					else{
						break;
					}
				}
				if(w3<maxn){
					w3++;	
				}
				else{
					ans-=c3[w3];
				}
				ans+=a[i][2];
		    }
		}
		cout<<ans<<endl;
	}
	return 0;
}
