// 通知 - CSPJS考场常见问题解答
// Q: 为什么文件（.in, .out）一打开就死机？
// A: 一般的编辑器（包括文本编辑器、CodeBlocks、VSCode等）能打开的文件不能太大，如果你打开一个过大的文件，编辑器一直在读文件，又占用很大内存，可能会导致整个操作系统卡死。所以最好不要打开过大的文件（比如大于1MB的文件）。
// Q: 有程序没响应，自己能关掉吗？
// A: 可以自己关闭程序。
// Q: 机器卡死了怎么办？
// A: 如果自己的程序已经存好了，自己可以关掉卡死的程序。关不了就举手找老师。
// Q: 运行的时候显示“段错误，核心已转储”该怎么办？
// A: 这个意思就是你的程序“运行错误”了，主要是访问了不该访问的地址，包括数组下标越界、指针错误、栈空间错误等等都可能显示这个错误。遇到这种情况，请好好检查自己的程序哪里写错了吧。
// Q: 我的程序写得很好，为什么编译不了？是不是环境坏了？
// A: 如果编译不了，请检查以下问题：
// l 如果你保存的路径中包含中文（例如存在桌面），可能导致部分编辑环境（包括CodeBlocks）无法编译，你可以存在主文件夹下面，或者在主文件夹下面建一个自己考号名字的文件夹，存在这个文件夹下。
// l 如果你的程序使用的数组过大，可能导致无法编译。典型的错误情况包括定义 1000000000 这么大的int数组。你可以试试调整数组的大小是否能解决问题。
// l 如果你编译一个 hello.cpp ，但是与 hello.cpp 在同一个目录有一个名为 hello 的文件夹，可能导致编译不了，建议给程序或者文件夹改个名字，或者把程序放到其它目录编译。
// l 如果你正在运行一个程序没有结束，又编译程序，可能会编译不了。
// Q: 可以修改显示器分辨率吗？
// A: 千万不要，风险很大，改了可能就显示不了了。
// Q: 换座位后程序回收系统登录不了怎么办？
// A: 程序回收系统绑定了IP地址，换座位需要监考老师操作解绑IP后才能登录。
// Q: 输入的时候总是把右边的字符覆盖掉了，怎么办？
// A: 试着按一下 “insert” 键（在方向键左ß的上面的上面），输入试试。如果还不行，尝试两到三次。如果还不行举手找老师。
// Q: 键盘的数字键按了没反应怎么办？
// A: 试着按一下小键盘上的 “Num Lock” 键，再按数字。如果还不行，尝试两到三次。如果还不行举手找老师。
// Q: 怎么打开 .in , .out , .ans 文件？
// A: 先打开 文本编辑器，然后在文本编辑器里面打开想看的文件，也可以将文件拖动到文本编辑器里面打开。
// Q: 怎么切换中英文输入法？
// A: 屏幕右上角有当前系统的状态，在显示“zh”、“中”或“英”的地方点击鼠标，就可以选择输入法。
// Q: 我建立了输入文件 <试题名>.in ，但是我的程序读不到输入是为什么？
// A: 程序只能读到执行时的当前目录（默认是.cpp文件所在的目录）的文件，所以务必把 .in 文件和 .cpp 文件放在同一个目录下。
// Q: 我刚下载的题目和样例在哪里？
// A: 请在下载题目时选择保存文件，而不是打开文件。保存的文件一般在 主文件夹/下载 里面，或者在 <Home>/Downloads 下面。

// 先看T1T2，然后T3T4！
// 不要卡在一道题！！如果30min不行就过！
// 如果正解不会不要一直卡着，先把部分分拿了！
// 一定要对拍！对拍不需要多长时间！！然后在后台挂着。
// 自己造一些边界情况和极限数据！
// 调整状态，相信奇迹！
// 这是最重要的考试了，所以一定要冷静分析，不要慌，然后至少保一个题，然后把部分分拿了！
// 目标150pts，争取250pts，加油！！
// 可能出现上午的T4那种防AK题，不要紧张
// 对拍不要数据太大，既不方便调试也会有更小的概率随机不到边界数据.
// 上午什么机子卡死了，这个机子太流畅辣，但是对拍的时候卡顿是正常的！

// 编译选项
// 对于 C++ 语言
// ‐O2 ‐std=c++14 ‐static
// 注意事项(请仔细阅读)
// 1. 文件名(程序名和输入输出文件名)必须使用英文小写。
// 2. main 函数的返回值类型必须是 int,程序正常结束时的返回值必须是 0。
// 3. 若无特殊说明,结果的比较方式为全文比较(过滤行末空格及文末换行)。
// 4. 选手提交的程序源文件大小不得超过 100 KiB。
// 5. 提交的程序源文件的放置位置请参考各省的具体要求。
// 6. 程序可使用的栈空间内存限制与题目的内存限制一致。
// 7. 禁止在源代码中改变编译器参数(如使用 #pragma 命令)
// ,禁止使用系统结构相
// 关指令(如内联汇编)或其他可能造成不公平的方法。
// 8. 因违反上述规定而出现的问题,申诉时一律不予受理。
// 9. 只提供 Linux 格式附加样例文件。
// 10. 全国统一评测时采用的机器配置为:Intel Core Ultra 9 285K CPU @ 3.70 GHz
// (关闭睿频与能效核),内存 96 GB。上述时限以此配置为准。
// 11. 评测在当前最新公布的 NOI Linux 下进行,各语言的编译器版本以此为准。
// 试题解压密码：Ren5Jie4Di4Ling5%

// T1时空限制：1.0sec/512MB，20个数据
// T2时空限制：1.0sec/512MB，25个数据
// T3时空限制：1.0sec/2048MB，20个数据
// T4时空限制：1.0sec/512MB，25个数据

// Code by Happy-David_3367
// Problem: 2025CSP-S2#T1. 社团招新club
// 1435.cpp Time Limit Exceeded on Sample 1, 2, 3, 4, 5
// 1616.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1624.cpp Time Limit Exceeded on Sample 3, 4, 5
// 1734.cpp Wrong Answer on Sample 3, 4, 5
// 1749.cpp ?
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng (0);
// int T, n, a[100100][5], res[100100]; /* 1624.cpp deleted */
int T, n, a[100100][5]; /* 1624.cpp added */
inline void generator() {
	n = rng () % 10 + 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			a[i][j] = rng () % 10;
		}
	}
}
set<int> club[5], club12, club13, club23;
long long ans;
set<pair<int, int>> club1to2, club1to3, club2to3, club2to1, club3to1, club3to2;
long long baoli_dfs(int p, int cnt1, int cnt2, int cnt3, long long ans) {
	if (cnt1 * 2 > n) { /* 1624.cpp added */
		return 0; /* 1624.cpp added */
	} /* 1624.cpp added */
	if (cnt2 * 2 > n) { /* 1624.cpp added */
		return 0; /* 1624.cpp added */
	} /* 1624.cpp added */
	if (cnt3 * 2 > n) { /* 1624.cpp added */
		return 0; /* 1624.cpp added */
	} /* 1624.cpp added */
	if (p == n + 1) {
		return ans;
	}
	long long ret = -1;
	ret = max (ret, baoli_dfs (p + 1, cnt1 + 1, cnt2, cnt3, ans + a[p][1]));
	ret = max (ret, baoli_dfs (p + 1, cnt1, cnt2 + 1, cnt3, ans + a[p][2]));
	ret = max (ret, baoli_dfs (p + 1, cnt1, cnt2, cnt3 + 1, ans + a[p][3]));
	return ret;
}
inline long long baoli() {
	// for (int i = 1; i <= n; ++i) { /* 1624.cpp deleted */
		// res[i] = 0; /* 1624.cpp deleted */
	// } /* 1624.cpp deleted */
	return baoli_dfs (1, 0, 0, 0, 0LL);
}
inline long long solve(long bg = 2147483647, bool during_duipai = false) {
	// long long res = baoli (); /* 1616.cpp added */ /* 1624.cpp deleted */
	// printf ("%lld\n", res); /* 1616.cpp added */ /* 1624.cpp deleted */
	// return res; /* 1616.cpp added */ /* 1624.cpp deleted */
	if (!during_duipai) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				scanf ("%d", &a[i][j]);
			}
		}
	}
	if (n > 17) { /* 1734.cpp added */
		priority_queue<pair<int, pair<int, int>>> q; /* 1734.cpp added */
		for (int i = 1; i <= n; ++i) { /* 1734.cpp added */
			for (int j = 1; j <= 3; ++j) { /* 1734.cpp added */
				q.push ({a[i][j], {i, j}}); /* 1734.cpp added */
			} /* 1734.cpp added */
		} /* 1734.cpp added */
		set<int> vis; /* 1734.cpp added */
		ans = 0; /* 1734.cpp added */
		int lft[4] = {0, n >> 1, n >> 1, n >> 1}; /* 1734.cpp added */
		while (!q.empty ()) { /* 1734.cpp added */
			int res = q.top ().first, i = q.top ().second.first, j = q.top ().second.second; /* 1734.cpp added */
			q.pop (); /* 1734.cpp added */
			if (vis.find (i) == vis.end ()) { /* 1734.cpp added */
				if (lft[j]) { /* 1734.cpp added */
					--lft[j]; /* 1734.cpp added */
					vis.insert (i); /* 1734.cpp added */
					ans += res; /* 1749.cpp added */
				} /* 1734.cpp added */
			} /* 1734.cpp added */
		} /* 1734.cpp added */
		printf ("%lld\n", ans); /* 1734.cpp added */
		return ans; /* 1734.cpp added */
	} /* 1734.cpp added */
	long long res = baoli (); /* 1624.cpp added */
	printf ("%lld\n", res); /* 1624.cpp added */
	return res; /* 1624.cpp added */
	club[1].clear ();
	club[2].clear ();
	club[3].clear ();
	club12.clear ();
	club13.clear ();
	club23.clear ();
	club1to2.clear ();
	club1to3.clear ();
	club2to3.clear ();
	club2to1.clear ();
	club3to1.clear ();
	club3to2.clear ();
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		ans += max (a[i][1], max (a[i][2], a[i][3]));
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			club[1].insert (i);
		}
		if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			club[2].insert (i);
		}
		if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
			club[3].insert (i);
		}
		if (club[1].count (i) && club[2].count (i)) {
			club12.insert (i);
		}
		if (club[1].count (i) && club[3].count (i)) {
			club13.insert (i);
		}
		if (club[2].count (i) && club[3].count (i)) {
			club23.insert (i);
		}
	}
	while (club12.size () && club[1].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club[1].erase (*club12.begin ());
		club12.erase (club12.begin ());
	}
	while (club12.size () && club[2].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club[2].erase (*club12.begin ());
		club12.erase (club12.begin ());
	}
	while (club13.size () && club[1].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club[1].erase (*club13.begin ());
		club13.erase (club13.begin ());
	}
	while (club13.size () && club[3].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club[3].erase (*club13.begin ());
		club13.erase (club13.begin ());
	}
	while (club23.size () && club[2].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club[2].erase (*club23.begin ());
		club23.erase (club23.begin ());
	}
	while (club23.size () && club[3].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club[3].erase (*club23.begin ());
		club23.erase (club23.begin ());
	}
	for (auto i : club[1]) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club1to2.insert ({a[i][2] - a[i][1], 1});
		club1to3.insert ({a[i][3] - a[i][1], 1});
	}
	for (auto i : club[2]) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club2to1.insert ({a[i][1] - a[i][2], 1});
		club2to3.insert ({a[i][3] - a[i][2], 1});
	}
	for (auto i : club[3]) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		club3to1.insert ({a[i][1] - a[i][3], 1});
		club3to2.insert ({a[i][2] - a[i][3], 1});
	}
	go:
	while (club[1].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		if (club1to2.begin ()->first > club1to3.begin ()->first || club1to2.begin ()->first == club1to3.begin ()->first && club[3].size () >= club[2].size ()) {
			int p = club1to2.begin ()->second;
			club[1].erase (p);
			club[2].insert (p);
			club1to2.erase (club1to2.begin ());
			club1to3.erase ({a[p][3] - a[p][1], p});
			club2to1.insert ({a[p][1] - a[p][2], p});
			club2to3.insert ({a[p][3] - a[p][2], p});
		} else {
			int p = club1to3.begin ()->second;
			club[1].erase (p);
			club[3].insert (p);
			club1to3.erase (club1to3.begin ());
			club1to2.erase ({a[p][2] - a[p][1], p});
			club3to1.insert ({a[p][1] - a[p][3], p});
			club3to2.insert ({a[p][2] - a[p][3], p});
		}
	}
	while (club[2].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		if (club2to1.begin ()->first > club2to3.begin ()->first || club2to1.begin ()->first == club2to3.begin ()->first && club[3].size () >= club[1].size ()) {
			int p = club2to1.begin ()->second;
			club[2].erase (p);
			club[1].insert (p);
			club2to1.erase (club2to1.begin ());
			club2to3.erase ({a[p][3] - a[p][2], p});
			club1to2.insert ({a[p][2] - a[p][1], p});
			club1to3.insert ({a[p][3] - a[p][1], p});
		} else {
			int p = club2to3.begin ()->second;
			club[2].erase (p);
			club[3].insert (p);
			club2to3.erase (club2to3.begin ());
			club2to1.erase ({a[p][1] - a[p][2], p});
			club3to1.insert ({a[p][1] - a[p][3], p});
			club3to2.insert ({a[p][2] - a[p][3], p});
		}
	}
	while (club[3].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		if (club3to1.begin ()->first > club3to2.begin ()->first || club3to1.begin ()->first == club3to2.begin ()->first && club[2].size () >= club[1].size ()) {
			int p = club3to1.begin ()->second;
			club[3].erase (p);
			club[1].insert (p);
			club3to1.erase (club3to1.begin ());
			club3to2.erase ({a[p][2] - a[p][3], p});
			club1to2.insert ({a[p][2] - a[p][1], p});
			club1to3.insert ({a[p][3] - a[p][1], p});
		} else {
			int p = club3to2.begin ()->second;
			club[3].erase (p);
			club[2].insert (p);
			club3to2.erase (club3to2.begin ());
			club3to1.erase ({a[p][1] - a[p][3], p});
			club2to1.insert ({a[p][1] - a[p][2], p});
			club2to3.insert ({a[p][3] - a[p][2], p});
		}
	}
	if (club[1].size () * 2 > n || club[2].size () * 2 > n || club[3].size () * 2 > n) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		goto go;
	}
	ans = 0;
	for (auto i : club[1]) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		ans += a[i][1];
	}
	for (auto i : club[2]) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		ans += a[i][2];
	}
	for (auto i : club[3]) {
		#ifdef Happy_David_3367_FLAG
			if (clock () - bg > CLOCKS_PER_SEC) {
				printf ("Time Limit Exceeded\n");
				return -1;
			}
		#endif
		ans += a[i][3];
	}
	printf ("%lld\n", ans);
	return ans;
}
int mian() {
	scanf ("%d", &T);
	while (T--) {
		solve (clock ());
	}
	return 0;
}
int main() {
	#ifndef Happy_David_3367_FLAG
		freopen ("club.in", "r", stdin);
		freopen ("club.out", "w", stdout);
		return mian ();
	#else
		bool sample_accepted = true;
		freopen ("club1.in", "r", stdin);
		freopen ("1749.club1.out", "w", stdout);
		mian ();
		fclose (stdin);
		fclose (stdout);
		// if (system ("cmp club1.ans 1435.club1.out")) { /* 1616.cpp deleted */
			// fprintf (stderr, "Sample1 Wrong Answer\n"); /* 1616.cpp deleted */
			// sample_accepted = false; /* 1616.cpp deleted */
		// } /* 1616.cpp deleted */
		freopen ("club2.in", "r", stdin);
		freopen ("1749.club2.out", "w", stdout);
		mian ();
		fclose (stdin);
		fclose (stdout);
		// if (system ("cmp club2.ans 1435.club2.out")) { /* 1616.cpp deleted */
			// fprintf (stderr, "Sample2 Wrong Answer\n"); /* 1616.cpp deleted */
			// sample_accepted = false; /* 1616.cpp deleted */
		// } /* 1616.cpp deleted */
		freopen ("club3.in", "r", stdin);
		freopen ("1749.club3.out", "w", stdout);
		mian ();
		fclose (stdin);
		fclose (stdout);
		// if (system ("cmp club3.ans 1435.club3.out")) { /* 1616.cpp deleted */
			// fprintf (stderr, "Sample3 Wrong Answer\n"); /* 1616.cpp deleted */
			// sample_accepted = false; /* 1616.cpp deleted */
		// } /* 1616.cpp deleted */
		freopen ("club4.in", "r", stdin);
		freopen ("1749.club4.out", "w", stdout);
		mian ();
		fclose (stdin);
		fclose (stdout);
		// if (system ("cmp club4.ans 1435.club4.out")) { /* 1616.cpp deleted */
			// fprintf (stderr, "Sample4 Wrong Answer\n"); /* 1616.cpp deleted */
			// sample_accepted = false; /* 1616.cpp deleted */
		// } /* 1616.cpp deleted */
		freopen ("club5.in", "r", stdin);
		freopen ("1749.club5.out", "w", stdout);
		mian ();
		fclose (stdin);
		fclose (stdout);
		// if (system ("cmp club5.ans 1435.club5.out")) { /* 1616.cpp deleted */
			// fprintf (stderr, "Sample5 Wrong Answer\n"); /* 1616.cpp deleted */
			// sample_accepted = false; /* 1616.cpp deleted */
		// } /* 1616.cpp deleted */
		// if (sample_accepted) { /* 1616.cpp deleted */
			// for (int test = 1; true; ++test) { /* 1616.cpp deleted */
				// fprintf (stderr, "Test #%d: ", test); /* 1616.cpp deleted */
				// generator (); /* 1616.cpp deleted */
				// if (baoli () != solve (true)) { /* 1616.cpp deleted */
					// fprintf (stderr, "Wrong Answer!\nData:\n"); /* 1616.cpp deleted */
					// fprintf (stderr, "%d\n", n); /* 1616.cpp deleted */
					// for (int i = 1; i <= n; ++i) { /* 1616.cpp deleted */
						// for (int j = 1; j <= 3; ++j) { /* 1616.cpp deleted */
							// fprintf (stderr, "%d ", a[i][j]); /* 1616.cpp deleted */
						// } /* 1616.cpp deleted */
						// fprintf (stderr, "\n"); /* 1616.cpp deleted */
					// } /* 1616.cpp deleted */
					// break; /* 1616.cpp deleted */
				// } else { /* 1616.cpp deleted */
					// fprintf (stderr, "Accepted.\n"); /* 1616.cpp deleted */
				// } /* 1616.cpp deleted */
			// } /* 1616.cpp deleted */
		// } /* 1616.cpp deleted */
	#endif
	return 0;
}