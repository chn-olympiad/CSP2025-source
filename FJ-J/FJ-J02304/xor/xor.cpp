#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans;
int a[N],sum[N],b[25],c[25],d[25];
int temp;
struct node{
	int pa,qa;
}t[N],l[N];
void merge(int L,int R){
	if(L>=R) return;
	int mid=L+R>>1;
	merge(L,mid);
	merge(mid+1,R);
	int i=L,j=mid+1;
	int k=L;
	while(i<=mid and j<=R)
		if(t[i].qa<t[j].qa){
			l[k].qa=t[i].qa;
			l[k++].pa=t[i++].pa;
		}else if(t[i].qa>t[j].qa){
			l[k].qa=t[j].qa;
			l[k++].pa=t[j++].pa;
		}else{
			if(t[i].pa<t[j].pa){
				l[k].qa=t[i].qa;
				l[k++].pa=t[i++].pa;
			}else{
				l[k].qa=t[j].qa;
				l[k++].pa=t[j++].pa;
			}
		}
	while(i<=mid){
		l[k].qa=t[i].qa;
		l[k++].pa=t[i++].pa;
	}
	while(j<=R){
		l[k].qa=t[j].qa;
		l[k++].pa=t[j++].pa;
	}
	for(int i=L;i<=R;i++){
		t[i].pa=l[i].pa;
		t[i].qa=l[i].qa;
	} 
}
bool flag;
int f(int x,int y){
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	memset(d,0,sizeof d);
	int cnt=0;
	int len1=-1,len2=-1;
	while(x){
		len1++;
		b[len1]=x%2;
		x/=2;
	}
	while(y){
		len2++;
		c[len2]=y%2;
		y/=2;
	}
	int len3=max(len1,len2);
	for(int i=0;i<=len3;i++){
		d[i]=(b[i]+c[i])%2;
		cnt+=d[i]*pow(2,i);
	}
	return cnt;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) flag=1;
		sum[i]=f(sum[i-1],a[i]);
	}
	if(!flag){
		for(int i=1;i<=n;i++)
			if(a[i]==k) ans++;
		printf("%d",ans);
		return 0;
	}else{
		for(int L=1;L<=n;L++){
			for(int i=1;i+L-1<=n;i++){
				int j=i+L-1;
				int p=f(sum[j],sum[i-1]);
				if(p==k){
					temp++;
					t[temp].pa=i;
					t[temp].qa=j;
				}
			}
		}
		merge(1,temp);
		int asd=0;
		for(int i=1;i<=temp;i++){
			if(asd<t[i].pa){
				asd=t[i].qa;
				ans++;
			}
		}
		printf("%d",ans);
	}
	return 0;
} 
