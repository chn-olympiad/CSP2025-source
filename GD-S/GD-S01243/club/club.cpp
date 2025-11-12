#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long am;
	long long bm;
	long long cm;
};
bool aaa(Node a,Node b){
	if(a.am==b.am){
		if(a.bm==b.bm){
			return a.cm<b.cm;
		}
		return a.bm<b.bm;
	}
	return a.am<b.am;
}
void sss(){
	int n;
	cin>>n;
	vector<Node> arr(n);
	bool a=1,b=1,c=1;
	for(long long i=0;i<n;i++){
		cin>>arr[i].am>>arr[i].bm>>arr[i].cm;
		if(arr[i].am!=0) c=0;
		if(arr[i].bm!=0) a=0;
		if(arr[i].cm!=0) b=0;
	}
	if(a&&b||a&&c||b&&c){
		sort(arr.begin(),arr.end(),aaa);
		long long z=0;
		for(int i=0;i<=n/2;i++){
			z=z+max(arr[i].am,max(arr[i].bm,arr[i].cm));
		}
		cout<<z<<endl;
		return ;
	}else if(b||a||c){
		long long z=0,az=0,bz=0,cz=0;
		sort(arr.begin(),arr.end(),aaa);
		for(long long i=0;i<n;i++){
			if((arr[i].am>arr[i].bm||bz==n/2&&cz==n/2)&&az<n/2){
				z=z+arr[i].am;
				az++;
			}else if(arr[i].bm>arr[i].cm||cz==n/2){
				z=z+arr[i].bm;
				bz++;
			}else{
				z=z+arr[i].cm;
				cz++;
			}
		}
		cout<<z<<endl;
		return ;
	}
	long long z=0,az=0,bz=0,cz=0;
	sort(arr.begin(),arr.end(),aaa);
	for(long long i=0;i<n;i++){
		if((arr[i].am>arr[i].bm&&arr[i].am>arr[i].cm||bz==n/2&&cz==n/2)&&az<n/2){
			z=z+arr[i].am;
			az++;
		}else if(arr[i].bm>arr[i].cm||cz==n/2){
			z=z+arr[i].bm;
			bz++;
		}else{
			z=z+arr[i].cm;
			cz++;
		}
	}
	cout<<z<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		sss();
	}
	return 0;
} 
