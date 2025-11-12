#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int l[n];
	int i1;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
		if(l[j]>l[j+1]) swap(l[j],l[j+1]);
	}
	}
	if(n==3){
	
	if(l[0]+l[1]+l[2]>2*l[2]) sum++;
	cout<<sum;
	return 0;
	
}
	if(n<=2){
		cout<<0;
		return 0;
	}

	for(int i=0;i<n;i++){
	i1=0;	
		for(int j=i;j<n;j++){
			i1+=l[i+j];
			//cout<<i+j <<" ";
		}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																														//*你猜测有一个因不会做题而无聊到极致的人在这里写了个完全没人看的注释		
		cout<<i1<<endl; 
		if(i1>2*l[n-1]) sum=sum+1;
	}
	i1=0;
	
	//班里有一群人英语考试开始后1分钟就在睡觉，现在我理解他们了。
	//困了 
	cout<<sum; 
}
