#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int T,n,a,b,c,sum;
struct node{
	int w1,w2,w3,id;
};
vector<node> k1,k2,k3;
bool cmp(node ax,node bx){
	if(ax.id==1){
		return (-ax.w1+max(ax.w2,ax.w3))>(-bx.w1+max(bx.w2,bx.w3)); 
	}
	else if(ax.id==2){
		return (-ax.w2+max(ax.w1,ax.w3))>(-bx.w2+max(bx.w1,bx.w3)); 
	}
	else if(ax.id==3){
		return (-ax.w3+max(ax.w1,ax.w2))>(-bx.w3+max(bx.w1,bx.w2)); 
	}
	return true;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		sum=0;
		k1.clear();
		k2.clear();
		k3.clear();
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			if(a>b&&a>c){
				k1.push_back(node{a,b,c,1});
				sum+=a;
			}
			else if(b>a&&b>c){
				k2.push_back(node{a,b,c,2});
				sum+=b; 
			}
			else if(c>a&&c>b){
				k3.push_back(node{a,b,c,3});
				sum+=c; 
			}
			else if(a==b&&b==c){
				k1.push_back(node{a,b,c,1});
				sum+=a;
			}
			else if(a==b){
				if(c>a){
					k3.push_back(node{a,b,c,3});
					sum+=c; 
				}
				else{
					k1.push_back(node{a,b,c,1});
					sum+=a; 
				}
			}
			else if(a==c){
				if(b>a){
					k2.push_back(node{a,b,c,2});
					sum+=b;
				}
				else{
					k1.push_back(node{a,b,c,1});
					sum+=a;
				}
			}
			else if(b==c){
				if(a>b){
					k1.push_back(node{a,b,c,1});
					sum+=a;
				}
				else{
					k2.push_back(node{a,b,c,2});
					sum+=b; 
				}
			}
		}
//		for(auto i:k1) printf("%d %d %d)",i.w1,i.w2,i.w3);
//		printf("\n");
//		for(auto i:k2) printf("%d %d %d)",i.w1,i.w2,i.w3);
//		printf("\n");
//		for(auto i:k3) printf("%d %d %d)",i.w1,i.w2,i.w3);
//		printf("\n");
//		printf("%d\n",sum);
		if(k1.size()>n/2){
			sort(k1.begin(),k1.end(),cmp);
			for(int i=0;i<k1.size()-(n/2);i++){
				sum=sum-k1[i].w1+max(k1[i].w2,k1[i].w3);
			}
		}
		else if(k2.size()>n/2){
			sort(k2.begin(),k2.end(),cmp);
			for(int i=0;i<k2.size()-(n/2);i++){
				sum=sum-k2[i].w2+max(k2[i].w1,k2[i].w3);
			}
		}
		else if(k3.size()>n/2){
			sort(k3.begin(),k3.end(),cmp);
			for(int i=0;i<k3.size()-(n/2);i++){
				sum=sum-k3[i].w3+max(k3[i].w1,k3[i].w2);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
