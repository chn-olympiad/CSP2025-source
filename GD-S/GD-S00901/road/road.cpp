#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		sum+=c;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*听说打完没事干可以骂CCF，虽然我没什么反对的，但是为什么这次变这么多？？
先是费用，费用s组和j组都涨了这么多,ccf你收这么多要搞什么活动？？全民学习科普c++吗？你们交税了吗？
然后这个目录，怎么又要加什么选手名字文本文档？还没有格式要求，那要来干嘛？
还有准考证号上抄文件大小？要受准考证吗？要用来干什么？我们自己的身份证号什么的个人隐私都在上面嘞，处理不好谁负责？？后果呢。。。*/ 
