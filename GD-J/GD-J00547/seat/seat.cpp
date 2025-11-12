#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void fropen(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
struct node{
	int score;
	bool isR;
};
node scores[109];
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	//Water problem. It must be 100pts!
	fropen("seat");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>scores[i].score;
		if(i==1)scores[i].isR=true;
	}
	sort(scores+1,scores+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(scores[i].isR){
			int col=i/n+1,row=0;
			if(col%2==1){
				row=i%n;
				if(row==0){
					col--;
					row=n;
				}
			}else{
				row=n-i%n+1;
			}
			cout<<col<<' '<<row;
			break;
		}
	}
	return 0;
}
