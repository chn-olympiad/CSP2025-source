#include<bits/stdc++.h>
using namespace std;
int mon[1005][1005]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	vector<int> G[12];
	int st[1005]={0};
	int n,m,k;cin>>n>>m>>k;
	for(int i=1,l,r,a;i<=m;i++){
	    cin>>l>>r>>a;
	    mon[l][r]=a;
	}
	for(int i=1;i<=k;i++){
		for(int j=0,num;j<=n;j++){
			cin>>num;
			G[i].push_back(num);
		}
	}
	/*
	致尊敬的张老师：
	  您好，我很抱歉，我已经没法想了，S组的确很难，我真的需要在过一年才有一定可能，我毕竟只学习了不到一年而已
	  我对不起过去的自己，很抱歉，你想着今年就可以去到文庙，对不起我没有完成
	  我不会气馁，我会继续努力，争取明年可以有好的成绩，确实世上没有任何一条路是好走的
	  我相信我可以，对不起未来的自己，接力棒已经交给你了，希望你带着我们共同的愿望走下去，不要放弃！
	  请未来的你记住我们永远都在，我们永远支持你，永远爱你！你只需要往前走，往前看就可以了！
	致尊敬的评委老师：
	  谢谢老师，您辛苦了，这个代码不用看了没有输出，我明年再来了！
	*/
	return 0;
}