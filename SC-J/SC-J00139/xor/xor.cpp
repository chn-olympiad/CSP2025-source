#include<bits/stdc++.h>
using namespace std;
vector<int> a;
struct box{
	int left;
	int right;
};
vector<box> bx;
long long my_xor(int l,int r){
	if(l==r)return a[l];
	int la=a[l],ra=a[r];
	long long ans=la;
	for(int i=l+1;i<=r;++i){
		ans=ans xor a[i];
	}
	return ans;
}
void search(long long kx,int n){
	long long ans=0;
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			if(my_xor(i,j)==kx){
				box tp;
				tp.left=i;
				tp.right=j;
				bx.push_back(tp);
			}
		}
	}
}
bool cmp(box a,box b){
	int sa=a.right-a.left;int lb=b.right-b.left;
	if(a.left!=b.left)return a.left<b.left;
	else return sa<lb;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,temp;long long k;cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>temp;
		a.push_back(temp);
	}
	search(k,n);
	sort(bx.begin(),bx.end(),cmp);
	int ans=0,curr=0;
	for(int i=0;i<bx.size();++i){
		//bx[i].left bx[i].right
//		printf("debug left:%d\n",bx[i].left);
//		printf("debug right:%d\n",bx[i].right);
		if(bx[i].left>=curr){
			ans++;curr=bx[i].right+1;
		}
	}
//	printf("debug myxor11:%d\n",my_xor(0,0));
//	printf("debug myxor24:%d\n",my_xor(1,3));
	cout<<ans;
	//printf("debug:% \n", )
//	cout<<;对应原题2,4  所以一定要记得减一 
	return 0;
}