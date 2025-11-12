#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        long long a[100001],b[100001],c[100001]，fl1[100001],fl2[100001],fl3[100001],q,w,e,gl1[100001],gl2[100001],gl3[100001],kl1[100001],kl2[100001],kl3[100001];
		long long ans=0,asdf=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=b[i]&&a[i]>=c[i]){
            	q++;
            	fl1[q]=a[i];
            	gl1[q]=b[i];
            	kl1[q]=c[i];
            }
            else if(a[i]<=b[i]&&b[i]>=c[i]){
            	w++;
            	fl2[q]=a[i];
            	gl2[q]=b[i];
            	kl2[q]=c[i];
            }
            else{
            	e++;
            	fl3[q]=a[i];
            	gl3[q]=b[i];
            	kl3[q]=c[i];
            }
            if(b[i]==0){
                asdf++;
            }
        }
        if(asdf==n){
            sort(a+1,a+1+n);
            for(int i=n;i>=n/2;i--){
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else if(n==2){
            int as=a[1]+a[2];
            if(a[1]+b[2]>as){
                as=a[1]+b[2];
            }
            else if(a[1]+c[2]>as){
                as=a[1]+c[2];
            }
            else if(b[1]+a[2]>as){
                as=b[1]+a[2];
            }
            else if(b[1]+b[2]>as){
                as=b[1]+b[2];
            }
            else if(b[1]+c[2]>as){
                as=b[1]+c[2];
            }
            else if(c[1]+a[2]>as){
                as=c[1]+a[2];
            }
            else if(c[1]+b[2]>as){
                as=c[1]+b[2];
            }
            else{
                as+=c[1]+c[2];
            }
            cout<<as<<endl;
            continue;
        }
        int y=0;
        while(1){
        	y=0;
        	if(q>n/2){
        		y=1;
        		int z=1,x=fl2[1],c=2;
        		for(int i=2;i<=q;i++){
        			if(fl2[i]>x){
        				x=fl2[i];
        				z=i;
        				c=2;
        			}
        			if(fl3[i]>x){
        				x=fl3[i];
        				z=i;
        				c=3;
        			}
        		}
        		if(c==2){
        			fl1[z]=0;
        			w++;
        			gl2[w]=fl2[z];
        			gl3[w]=fl3[z];
        		}
        		else{
        			fl1[z]=0;
        			e++;
        			kl3[e]=fl3[z];
        			kl2[e]=fl2[z];
        		}
        	}
        	if(w>n/2){
        		y=1;
        		int z=1,x=gl1[1],c=1;
        		for(int i=2;i<=q;i++){
        			if(gl1[i]>x){
        				x=gl1[i];
        				z=i;
        				c=1;
        			}
        			if(gl3[i]>x){
        				x=gl3[i];
        				z=i;
        				c=3;
        			}
        		}
        		if(c==1){
        			gl2[z]=0;
        			q++;
        			fl1[q]=gl1[z];
        			fl3[q]=gl3[z];
        		}
        		else{
        			gl2[z]=0;
        			e++;
        			kl3[e]=gl3[z];
        			kl1[e]=gl1[z];
        		}
        	}
        	if(e>n/2){
        		y=1;
        		int z=1,x=kl1[1],c=1;
        		for(int i=2;i<=q;i++){
        			if(kl1[i]>x){
        				x=kl1[i];
        				z=i;
        				c=1;
        			}
        			if(kl2[i]>x){
        				x=kl2[i];
        				z=i;
        				c=2;
        			}
        		}
        		if(c==1){
        			kl3[z]=0;
        			q++;
        			fl1[q]=kl1[z];
        			fl2[q]=kl2[z];
        		}
        		else{
        			kl1[z]=0;
        			w++;
        			kl3[w]=kl1[z];
        			fl2[w]=fl1[z];
        		}
        	}
        	if(y==0){
        		break;
        	}
        }
        for(int i=1;i<=q;i++){
        	ans+=fl1[i];
        }
        for(int i=1;i<=w;i++){
        	ans+=gl2[i];
        }
        for(int i=1;i<=e;i++){
        	ans+=kl3[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
