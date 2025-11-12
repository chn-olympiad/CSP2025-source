#include<bits/stdc++.h>
using namespace std;
struct node{
	int xy,num;
}s[510000];
int a[510000];
	int n,k;
bool cmp(node x,node y){
	if(x.num==y.num){
		return x.xy<y.xy;
	}
	return x.num<y.num;
}
int ddd(int x,int xy){
	int nd=k^x;
	int left=1,right=n,ans=-1;
	//cout<<nd<<endl;
	while(left<=right){
		int mid=(left+right)/2;
		if(s[mid].num>nd){
			right=mid-1;
		}
		else if(s[mid].num<nd){
			left=mid+1;
		}
		else if(s[mid].num==nd&&xy<=s[mid].xy){
			ans=mid;
			right=mid-1;
		}else{
			left=mid+1;
		}
		//cout<<left<<' '<<right<<' '<<mid<<' '<<s[mid].num<<' '<<s[mid].xy<<endl;
	}
	if(ans==-1){
		return -1;
	}else{
		//cout<<s[ans].xy<<endl;
		return s[ans].xy;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	s[1].xy=1;s[1].num=a[1];
	for(int i=2;i<=n;i++){
		cnt=cnt^a[i];
		a[i]=cnt;
		s[i].num=cnt;
		s[i].xy=i;
	}
	sort(s+1,s+1+n,cmp);
	int ans=0;
	int i=1;
	while(i<=n){
		int ineed=s[i-1].num;
		int f=ddd(ineed,i);
		if(f==-1){
			i++;
			continue;
		}else{
			i=f+1;
			ans++;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
