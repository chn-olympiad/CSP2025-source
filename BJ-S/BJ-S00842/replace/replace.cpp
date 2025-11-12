#include<iostream>
#include<cmath>
using namespace std;
int n,q;
const int N = 2e5+10;
pair<string,string> replace[N];
string f,t;
void rep(int start,int i){
  for(int j = start;j<start+replace[i].second.length();j++){
    f[j]=replace[i].second[j-start];
  }
}
bool check(int start,int i){
	for(int k = 0;k<replace[i].first.length();k++){
	  if(f[start+k]!=replace[i].first[k]){
	    return false;

	  }
	}
	return true;
}
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);  
  cin>>n>>q;
  for(int i = 0;i<n;i++){
    string a,b;
    cin>>a>>b;
    replace[i] = make_pair(a,b);
  }
  while(q--){
    cin>>f>>t;
    string oldf;
    oldf = f;
    int cnt = 0;
    for(int i = 0;i<n;i++){
      for(int j = 0;j<=max(0,(int)f.length()-(int)replace[i].first.length());j++){
	//	cout<<j<<' ';
	if(check(j,i)){
	  rep(j,i);
	  //	  cout<<"a "<<replace[i].first<<' '<<f<<endl;	  
	  if(f==t){
	    cnt++;
	  }
	  f = oldf;
	}
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
