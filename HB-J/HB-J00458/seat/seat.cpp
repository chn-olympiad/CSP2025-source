#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
}

pair<int,int> lst[100];

int bs(int l,int r,int mb){
	int mid=(l+r)/2;
	int out;
	if(lst[mid].second==mb) return mid;
	else if(lst[mid].second>mb) out=bs(mid+1,r,mb);
	else out=bs(l,mid-1,mb);
	return out;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin >> c >> r;
	for(int i=1;i<=c*r;i++){
		lst[i-1].first = i;
		cin >> lst[i-1].second;
	}
	int sc = lst[0].second;
	sort(lst,lst+(c*r),cmp);
	int out=bs(0,c*r-1,sc);
	int pos_c = out%c;
	int pos_r = out/c;
	if(pos_r%2) pos_c=c-1-pos_c;
	cout << pos_r+1 << " " << pos_c+1;
	return 0;
}
