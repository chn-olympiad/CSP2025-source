#include<bits/stdc++.h>
using namespace std;
namespace leo {
  ifstream fin("seat.in");
  ofstream fout("seat.out");
  #define cin fin
  #define cout fout
  int read() {
    int d=0; char c;
    c=cin.get();
    while(!isdigit(c))  c=cin.get();
    while(isdigit(c)) {
      d=d*10+(c^'0');
      c=cin.get();
	}
	return d;
  }
  int n,m,c,r,score,p;
  vector<int> grade;
  void sort(vector<int> &a) {
    priority_queue<int> q;
    for(int i=0;i<a.size();i++)
      q.push(a[i]);
    for(int i=0;i<a.size();i++) {
      a[i]=q.top();
      q.pop();
	}
  }
//  int find(vector<int> a,int v) {
//    int l=0,r=a.size()-1,mid,ans=-1;
//    while(l<=r) {
//      mid=(l+r)>>1;
//      if(a[mid]==v) {
//        ans=mid;
//        break;
//	  }
//	  if(a[mid]<v)
//	    r=mid-1;
//	  else
//	    l=mid+1;
//	}
//	return ans; 
//  }
  void main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    n=read(); m=read();
    for(int i=0;i<n*m;i++) {
      score=read();
      grade.emplace_back(score);
	}
	score=grade[0];
	sort(grade);
	for(int i=0;i<grade.size();i++)
	  if(grade[i]==score) {
	    p=i+1;
	    break;
	  }
//	p=find(grade,score)+1;
	c=p/n;
	p=p%n;
	if(p)
	  c++;
	else
	  p=n;
	if(c%2)
	  r=p;
	else
	  r=n-p+1;
	cout<<c<<' '<<r<<'\n';
  }
}
int main() {
  leo::main();
}

