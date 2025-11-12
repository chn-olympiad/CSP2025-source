#include<bits/stdc++.h>
using namespace std;
struct ran{
	int left,right,numcon;
	bool operator<(const ran other)const{
		return left==other.left?right<other.right:left<other.left;
	}
}a[500505];
struct cmp{
	int id,num;
}larright;
int n,k,an[500005],ans,top,del[500505];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>an[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ta=an[i];
			for(int num=i+1;num<=j;num++){
				ta=ta^an[num];
			}
			if(ta==k){
				a[++top].left=i,a[top].right=j;
			}
		}
	}
	sort(a+1,a+top+1);
	larright.id=1,larright.num=a[1].right;
	for(int i=2;i<=top;i++){
		int x=i;
		while(x<=top){
			if(a[++x].left<=a[i].right){
				a[i].numcon++;
			}
		}
		if(larright.num>=a[i].left){	
			if(a[larright.id].numcon>=a[i].numcon){
				del[larright.id]=1;
				larright.num=a[i].right,larright.id=i;
			}
			else{
				del[i]=1;
			}
		}
	}
	for(int i=1;i<=top;i++){
		if(!del[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
