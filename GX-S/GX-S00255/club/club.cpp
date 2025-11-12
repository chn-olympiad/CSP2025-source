#include<bits/stdc++.h>
using namespace std;
struct memb{
	int a1;
	int a2;
	int a3;
}m[100005];
int n1[5],n2[5];
int max(int a,int b,int c){
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	if(c>=a&&c>=b) return c;
	return 0;
}
bool c1(memb x,memb y){
	return x.a1>y.a1;
}
bool c2(memb x,memb y){
	return x.a2>y.a2;
}
bool c3(memb x,memb y){
	return x.a3>y.a3;
}
int b1[100005],b2[100005],b3[100005];
int a[100005];
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;
	int temp,index;
	scanf("%d",&t);
	for(int x=0;x<t;x++){		
		ans=0;
		n1[1]=0,n1[2]=0,n1[3]=0;
		n1[0]=0;
		temp=0,index=0;
		for(int i=0;i<n;i++){
			b1[i]=0,b2[i]=0,b3[i]=0,a[i]=0;
		}
		
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&m[i].a1,&m[i].a2,&m[i].a3);
			if(m[i].a1==max(m[i].a1,m[i].a2,m[i].a3)) n1[1]++;
			if(m[i].a2==max(m[i].a1,m[i].a2,m[i].a3)) n1[2]++;				
			if(m[i].a3==max(m[i].a1,m[i].a2,m[i].a3)) n1[3]++;
		}
		if(n1[1]<=n/2&&n1[2]<=n/2&&n1[3]<=n/2){
			for(int i=0;i<n;i++) ans+=max(m[i].a1,m[i].a2,m[i].a3);
			cout<<ans<<endl;
			continue;
		}
		if(n1[1]==max(n1[1],n1[2],n1[3])){
			sort(m,m+n+1,c1);						
			for(int i=0;i<n;i++){
				if(m[i].a1==max(m[i].a1,m[i].a2,m[i].a3) && n1[0]<n/2){
					b1[i]=m[i].a1;
					ans+=m[i].a1;
					n1[0]++;
					a[i]++;
				}
			}
			for(int i=0;i<n;i++){
				if(m[i].a1==max(m[i].a1,m[i].a2,m[i].a3) && b1[i]==0){
					
					temp=0;
					index=-1;
					for(int j=0;j<n && b1[j]!=0;j++){
						//cout<<m[i].a1+max(m[j].a2,m[j].a3)-b1[j]-max(m[i].a2,m[i].a3)<<endl;
						if(b1[i]==0){
							if(m[i].a1+max(m[j].a2,m[j].a3)-b1[j]-max(m[i].a2,m[i].a3)>temp){
								temp=m[i].a1+max(m[j].a2,m[j].a3)-b1[j]-max(m[i].a2,m[i].a3);
								index=j;
							}	
						}
					}
					if(index!=-1){
						b1[index]=0;
						b1[i]=m[i].a1;
						if(m[i].a2>m[i].a3) b2[index]=m[index].a2;
						else b3[index]=m[index].a3;
						ans+=temp;
					}else{
						if(m[i].a2>m[i].a3){
							b2[i]=m[i].a2;
							ans+=m[i].a2;
						}else{
							b3[i]=m[i].a3;
							ans+=m[i].a3;
						}
					}		
				}
				else if(a[i]==0){
					if(m[i].a2>m[i].a3){
						b2[i]=m[i].a2;
						ans+=m[i].a2;
					}else{
						b3[i]=m[i].a3;
						ans+=m[i].a3;
					}
				}
			}	
		}
		if(n1[2]==max(n1[1],n1[2],n1[3])){
			sort(m,m+n+1,c2);						
			for(int i=0;i<n;i++){
				if(m[i].a2==max(m[i].a1,m[i].a2,m[i].a3) && n1[0]<n/2){
					b2[i]=m[i].a2;
					ans+=m[i].a2;
					n1[0]++;
					a[i]++;
				}
			}
			for(int i=0;i<n;i++){
				if(m[i].a2==max(m[i].a1,m[i].a2,m[i].a3) && b2[i]==0){
					temp=0;
					index=-1;
					for(int j=0;j<n && b2[j]!=0;j++){
						//cout<<m[i].a1+max(m[j].a2,m[j].a3)-b1[j]-max(m[i].a2,m[i].a3)<<endl;
						if(b2[i]==0){
							if(m[i].a2+max(m[j].a1,m[j].a3)-b2[j]-max(m[i].a1,m[i].a3)>temp){
								temp=m[i].a2+max(m[j].a1,m[j].a3)-b2[j]-max(m[i].a1,m[i].a3);
								index=j;
							}
						}
					}
					if(index!=-1){
						b2[index]=0;
						b2[i]=m[i].a2;
						if(m[i].a1>m[i].a3) b1[index]=m[index].a1;
						else b3[index]=m[index].a3;
						ans+=temp;
					}else{
						if(m[i].a1>m[i].a3){
							b1[i]=m[i].a1;
							ans+=m[i].a1;
						}else{
							b3[i]=m[i].a3;
							ans+=m[i].a3;
						}
					}			
				}
				else if(a[i]==0){
					if(m[i].a1>m[i].a3){
						b1[i]=m[i].a1;
						ans+=m[i].a1;
					}else{
						b3[i]=m[i].a3;
						ans+=m[i].a3;
					}
				}
			}	
		}
		if(n1[3]==max(n1[1],n1[2],n1[3])){
			sort(m,m+n+1,c3);						
			for(int i=0;i<n;i++){
				if(m[i].a3==max(m[i].a1,m[i].a2,m[i].a3) && n1[0]<n/2){
					b3[i]=m[i].a3;
					ans+=m[i].a3;
					n1[0]++;
					a[i]++;
				}
			}
			for(int i=0;i<n;i++){
				if(m[i].a3==max(m[i].a1,m[i].a2,m[i].a3) && b3[i]==0){
					temp=0;
					index=-1;
					for(int j=0;j<n && b3[j]!=0;j++){
						//cout<<"temp="<<m[i].a1+max(m[j].a2,m[j].a3)-b1[j]-max(m[i].a2,m[i].a3)<<endl;
						if(b3[i]==0){
							if(m[i].a3+max(m[j].a2,m[j].a1)-b3[j]-max(m[i].a2,m[i].a1)>temp){
								temp=m[i].a3+max(m[j].a2,m[j].a1)-b3[j]-max(m[i].a2,m[i].a1);
								index=j;
							}
						}
					}
					if(index!=-1){
						b3[index]=0;
						b3[i]=m[i].a3;
						if(m[i].a2>m[i].a1) b2[index]=m[index].a2;
						else b1[index]=m[index].a1;
						ans+=temp;
					}else{
						if(m[i].a2>m[i].a1){
							b2[i]=m[i].a2;
							ans+=m[i].a2;
						}else{
							b1[i]=m[i].a1;
							ans+=m[i].a1;
						}
					}			
				}
				else if(a[i]==0){
					if(m[i].a2>m[i].a1){
						b2[i]=m[i].a2;
						ans+=m[i].a2;
					}else{
						b3[i]=m[i].a1;
						ans+=m[i].a1;
					}
				}
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
	
}
