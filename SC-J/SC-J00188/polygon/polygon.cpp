#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 5005, Q = 998244353;
int n, a[N];
ll f[N][N + 5];
int main() {
	//qwq rp++!
	//Ya int_4096 desu.
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	std::sort(a + 1, a + 1 + n);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < N; j++) {
			int pre = j - a[i];
			if (pre < 0) pre = 0;
			f[i][j] = (f[i - 1][j] + f[i - 1][pre]) % Q;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += f[i - 1][a[i] + 1];
		ans %= Q;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-J 2025
KaoShengMiHuoXingWeiDaShang:
8:40
Open T4.
sort it first,
and then the problem turned into
choose from [1..i] let it greater_equal than j.
that can be DPed.
But T3 is so difficult!
8:58
Go back to T4.
That's so fast.
9:03
finished, pass the samples.
10:15
I write chker for each program.
that's really tiring.
Now, time to write somthing as MiHuoXingWei!
10:22
In fact I'm so tired, I wanna sleep instead of writing these.
And I think nobody would make CSP-J MiHuoXingWeiDaShang.
But I have to take this shot.
bilibili GuanZhu ChiKuaiShuZhuPai XieXieMiao.
Luogu: int_4096
I yest to decide to write my OI adventure(or just story),
but I found that I might need to write that in YouJi so I won't
write it again right here.
I'm kinda worried, due to the S this afternoon.
And also, my english is bad, and mid-term exam is right behind me.
Anyway, now I'm on the way to the bright future, so I can still
look up and be happy.
Oh, my thoughts are not so clear. I'm really tired, maybe take a break?
Okay, 10:30 right now, I'm playing abstract right now.
first, list some nouns I kown:
EDM, phigros, arcaea, arknights, battlefield,
(wait, if I did this now, what I should do in the afternoon?
Oh, I probably have no time to do this that time.)
blue archive, minecraft, Genshin impact,
post-punk, Ave mujica, JinYiWei, HaJiMi,
Hatsune Miku, Kards, PVZ, CS2,
(Haha, WoZaiZheDie buff)
FL studio, Ablenton live, Logic, Cubase, Medly,
dnb, future house, deep house, future bass,
dubstep, garage, YinYouQu, synthwave.
Liquid funk, neuro funk, jungle, atomospheric dnb,
breakcore, melodic, jump up, roller.
Feint, Rameses B, Fox Stevenson, Mazare.
(This people might listen to too much dnb)
Okay, find what buff I have got now:
Electronic Music(Production)
Music Game
Some famous ErCiYuan YouXi
Minecraft
err, not very much, actually?
Oh, one thing important, yesterday I watched WeiLaiRiJi because I saw
Ynoi, but then I became so scared that I can't sleep well, leading to
the tiredness I got now.
No, I gotta think somthing more abstract.
Ahh, so sleepy, I'll sleep now.

"to myself to everyone else,
to my freinds and everyone in between"

If you are looking this words now,
..
I don't know how to cheer you up.
I'll use some sayings:
"people feels sad, and confused,
only because they look too close,
but think too far."
My journey of OI isn't very fascinating,
but to myself, every thing I've been,
is a story, a piece of memory.
It did took something from me,
but looking back to those,
I'll say "those were days".
2025/11/1 10:48
*/