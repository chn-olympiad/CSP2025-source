#include<iostream>
using namespace std;
int main(){
    char ch[50] = {};
    char ans[50] = {};
    int cnt0 = 0;
    int cnt = 0;
    cin>>ch;
    
    int tmp;
    for(int i = 0;i < n;i ++)
    {
    	if(ch[i] >= "0" && ch[i] <= "9")
    	{
    	    if(ch[i] == "0")
    	    {
    	    	cnt0 ++;
    	    }
    	    else{
    	    	ans[i] = ch[i];
    	    	if(ans[i] > ans[i - 1])
    	    	{
		    tmp = ans[i];
		    ans[i] = ans[i - 1];
		    ans[i - 1] = tmp;
    	    	}
    	    	cnt ++;
    	    }
    	}
    }
    
    int index = cnt - 1;
    for(int i = cnt0;i > 0;i --)
    {
    	ans[index] = "0";
    	index ++;
    }
    cout<<ans;
    return 0;
}
